/**
 * @file pffc_encoder.h
 * @author Powers (powertle@outlook.com)
 * @brief 编码器
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#ifndef __PFFC_ENCODER_H__
#define __PFFC_ENCODER_H__

#include "Pang.FFmpegCore.h"

// TODO: 函数声明

/**
 * @brief 打开编码器
 * 
 */
void encoder_open();

/**
 * @brief Get the frame size object
 * 
 * @return int 
 */
int get_frame_size();

/**
 * @brief 初始化编码器
 * 
 */
static void init_encoder();
/**
 * @brief 编码
 * 
 * @return bool 
 */
static bool encode(byte[], int, byte *);
/**
 * @brief 释放资源
 * 
 */
static void dispose();

// TODO: 函数声明

// TODO: 全局变量
AVCodec *codec_g = NULL;
AVCodecContext *codec_ctx_g = NULL;
AVFrame *frame_g = NULL;
AVPacket *pkt_g = NULL;

int frame_bytes_g;

int frame_size_g;

ulong pts_g = 0;

// TODO: 全局变量

void encoder_open()
{
    //init_encoder();
}

int get_frame_size()
{
    return frame_size_g;
}

/**
 * @brief 初始化解码器
 * 
 * @param audio_type 
 */
static void init_encoder(enum AudioType audio_type)
{
    enum AVCodecId codec_id;
    switch (audio_type)
    {
    case AUDIO_TYPE_AAC:
        codec_id = AV_CODEC_ID_AAC;
        break;
    case AUDIO_TYPE_MP3:
        codec_id = AV_CODEC_ID_MP3;
        break;
    default:
        break;
    }

    codec_g = avcodec_find_encoder(codec_id);
    if (!codec_g)
    {
        printf("Codec not found. \n");
        exit(1);
    }

    codec_ctx_g = avcodec_alloc_context3(codec_g);
    if (!codec_ctx_g)
    {
        printf("Could not allocate audio codec context. \n");
        exit(1);
    }

    codec_ctx_g->codec_id = codec_id;
    codec_ctx_g->codec_type = AVMEDIA_TYPE_AUDIO;
    codec_ctx_g->bit_rate = 128 * 1024;
    codec_ctx_g->channel_layout = AV_CH_LAYOUT_STEREO;
    codec_ctx_g->sample_rate = 48000;
    codec_ctx_g->channels = av_get_channel_layout_nb_channels(codec_ctx_g->channel_layout);
    codec_ctx_g->profile = FF_PROFILE_AAC_LOW;

    if (strcmp(codec_g->name, "aac") == 0)
    {
        codec_ctx_g->sample_fmt = AV_SAMPLE_FMT_FLTP;
    }
    else if (strcmp(codec_g->name, "libfdk_aac") == 0)
    {
        codec_ctx_g->sample_fmt = AV_SAMPLE_FMT_S16;
    }
    else
    {
        codec_ctx_g->sample_fmt = AV_SAMPLE_FMT_FLTP;
    }

    if (!check_sample_fmt(codec_g, codec_ctx_g->sample_fmt))
    {
        fprintf(stderr, "Encoder does not support sample format %s\n",
                av_get_sample_fmt_name(codec_ctx_g->sample_fmt));
        exit(1);
    }

    if (!check_sample_rate(codec_g, codec_ctx_g->sample_rate))
    {
        fprintf(stderr, "Encoder does not support sample rate %d\n",
                codec_ctx_g->sample_rate);
        exit(1);
    }

    if (!check_channel_layout(codec_g, codec_ctx_g->channel_layout))
    {
        fprintf(stderr, "Encoder does not support channel layout %lu\n",
                codec_ctx_g->channel_layout);
        exit(1);
    }

    printf("\n\nAudio encode config:\n");
    printf("bit_rate: %ldkbps\n", codec_ctx_g->bit_rate);
    printf("sample_rate: %d\n", codec_ctx_g->sample_rate);
    printf("sample_fmt: %s\n", av_get_sample_fmt_name(codec_ctx_g->sample_fmt));
    printf("channels: %d\n", codec_ctx_g->channels);
    printf("1 frame_size: %d\n", codec_ctx_g->frame_size);

    if (avcodec_open2(codec_ctx_g, codec_g, NULL) < 0)
    {
        fprintf(stderr, "Could not open codec.\n");
    }

    printf("2 frame_size: %d\n", codec_ctx_g->frame_size);

    pkt_g = av_packet_alloc();
    if (!pkt_g)
    {
        fprintf(stderr, "Could not allocate the packet.\n");
        exit(1);
    }

    frame_g = av_frame_alloc();
    if (!frame_g)
    {
        fprintf(stderr, "Could not allocate the frame.\n");
        exit(1);
    }
    frame_g->nb_samples = codec_ctx_g->frame_size;
    frame_g->format = codec_ctx_g->sample_fmt;
    frame_g->channel_layout = codec_ctx_g->channel_layout;
    frame_g->channels = av_get_channel_layout_nb_channels(frame_g->channel_layout);
    printf("frame nb_samples: %d\n", frame_g->nb_samples);
    printf("frame sample_fmt: %s\n", av_get_sample_fmt_name(frame_g->format));
    printf("frame channel_layout: %lu\n", frame_g->channel_layout);

    int ret;

    ret = av_frame_get_buffer(frame_g, 0);
    if (ret < 0)
    {
        fprintf(stderr, "Could not allocate audio data buffers.\n");
        exit(1);
    }

    frame_bytes_g = av_get_bytes_per_sample(frame_g->format * frame_g->channels * frame_g->nb_samples);
    printf("frame_bytes: %d\n", frame_bytes_g);

    frame_size_g = codec_ctx_g->frame_size;
}

/**
 * @brief 编码
 * 
 * @param input 
 * @param input_size 
 * @param output 
 * @return true 
 * @return false 
 */
static bool encode(byte input[], int input_size, byte *output)
{
    int ret;

    // 填充数据到缓冲区
    pffc_buffer_queue_enqueue_array(input, input_size);

    // 如果数据不够一帧, 则取消
    if (pffc_get_buffer_queue_size() < frame_bytes_g)
    {
        printf("buffer not enough 1 frame. buffer size: %d\n", pffc_get_buffer_queue_size());
        return false;
    }

    byte *pcm_buf = pffc_buffer_queue_dequeue_array(frame_bytes_g);
    if (!pcm_buf)
    {
        printf("pcm_buf malloc failed.\n");
        return false;
    }

    byte *pcm_temp_buf = malloc(frame_bytes_g);
    if (!pcm_temp_buf)
    {
        printf("pcm_temp malloc failed.\n");
        return false;
    }

    ret = av_frame_make_writable(frame_g);
    if (ret != 0)
    {
        printf("av_frame_make_writable failed, ret = %d\n", ret);
    }

    if (AV_SAMPLE_FMT_S16 == frame_g->format)
    {
        ret = av_samples_fill_arrays(frame_g->data,
                                     frame_g->linesize,
                                     pcm_buf,
                                     frame_g->channels,
                                     frame_g->nb_samples,
                                     frame_g->format, 0);
    }
    else
    {
    }
    return false;
}

static void dispose()
{
}

#endif // __PFFC_ENCODER_H__