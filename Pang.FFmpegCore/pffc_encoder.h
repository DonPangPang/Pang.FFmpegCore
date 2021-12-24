#pragma once

#ifndef __PFFC_ENCODER_H__
#define __PFFC_ENCODER_H__

#include "Pang.FFmpegCore.h"

// TODO: 函数声明

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
static bool encode(AVCodecContext *, AVFrame *, AVPacket *, byte *);
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

// TODO: 全局变量

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
    if(!codec_g)
    {
        printf("Codec not found. \n");
        exit(1);
    }
    
    codec_ctx_g = avcodec_alloc_context3(codec_g);
    if(!codec_ctx_g)
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

    if(strcmp(codec_g->name, "aac") == 0)
    {
        codec_ctx_g->sample_fmt = AV_SAMPLE_FMT_FLTP;
    }else if (strcmp(codec_g->name, "libfdk_aac") == 0){
        codec_ctx_g->sample_fmt = AV_SAMPLE_FMT_S16;
    }else{
        codec_ctx_g->sample_fmt = AV_SAMPLE_FMT_FLTP;
    }

    if(!check_sample_fmt(codec_g, codec_ctx_g->sample_fmt))
    {
        fprintf(stderr, "Encoder does not support sample format %s\n",
            av_get_sample_fmt_name(codec_ctx_g->sample_fmt));
        exit(1);
    }

    if(!check_sample_rate(codec_g, codec_ctx_g->sample_rate))
    {
        fprintf(stderr, "Encoder does not support sample rate %d\n",
            codec_ctx_g->sample_rate);
        exit(1);
    }

    if(!check_channel_layout(codec_g, codec_ctx_g->channel_layout))
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

    if(avcodec_open2(codec_ctx_g, codec_g, NULL) < 0)
    {
        fprintf(stderr, "Could not open codec.\n");
    }

    printf("2 frame_size: %d\n", codec_ctx_g->frame_size);

    pkt_g = av_packet_alloc();
    if(!pkt_g)
    {
        fprintf(stderr, "Could not allocate the packet.\n");
        exit(1);
    }

    frame_g = av_frame_alloc();
    if(!frame_g)
    {
        fprintf(stderr, "Could not allocate the frame.\n");
        exit(1);
    }
}

static bool encode(AVCodecContext *ctx, AVFrame *frame, AVPacket *pkt, byte *output)
{
    return false;
}

static void dispose()
{
}

#endif // __PFFC_ENCODER_H__