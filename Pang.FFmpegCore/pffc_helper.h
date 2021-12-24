#pragma once
#ifndef __PFFC_HELPER_H__
#define __PFFC_HELPER_H__

#include "Pang.FFmpegCore.h"

#endif // __PFFC_HELPER_H__

// TODO: 函数声明

/**
 * @brief 检查该编码器是否支持该采样格式
 * 
 * @return bool 
 */
static bool check_sample_fmt(const AVCodec*, enum AVSampleFormat);

/**
 * @brief 检查该编码器是否支持该采样率
 * 
 * @return bool 
 */
static bool check_sample_rate(const AVCodec*, const int);

/**
 * @brief 检查编码器是否支持该通道布局
 * 
 * @return bool 
 */
static bool check_channel_layout(const AVCodec, const ulong);

/**
 * @brief Get the adts header object
 * 
 */
static void get_adts_header(AVCodecContext*, byte*, int);

// TODO: 函数声明

/**
 * @brief 检查该编码器是否支持该采样格式
 * 
 * @param codec 编码器
 * @param sample_fmt 采样格式
 * @return bool 1:是 0:否
 */
static bool check_sample_fmt(const AVCodec* codec, enum AVSampleFormat sample_fmt)
{
    const enum AVSampleFormat *p = codec->sample_fmts;

    while(*p != AV_SAMPLE_FMT_NONE)
    {
        if(*p == sample_fmt)
        {
            return true;
        }
        p++;
    }
    return false;
}

/**
 * @brief 检查该编码器是否支持该采样率
 * 
 * @param codec 编码器
 * @param sample_rate 采样率
 * @return bool 
 */
static bool check_sample_rate(const AVCodec* codec, const int sample_rate)
{
    const int* p = codec->supported_samplerates;
    while (*p != 0)
    {
        printf("%s support %dhz \n", codec->name, *p);
        if(*p == sample_rate)
            return true;
        p++;
    }
    return false;
    
}

/**
 * @brief 检查编码器是否支持该通道布局
 * 
 * @param codec 
 * @param channel_layout 通道布局
 * @return bool 
 */
static bool check_channel_layout(const AVCodec* codec, const ulong channel_layout)
{
    const ulong* p = codec->channel_layouts;
    if(!p)
    {
        printf("the codec %s no set channel_layouts.", codec->name);
        return true;
    }

    while(*p != 0)
    {
        printf("%s support channel_layout %d \n", codec->name, *p);
        if(*p == channel_layout)
            return true;
        p++;
    }

    return false;
}

static void get_adts_header(AVCodecContext* ctx, byte* adts_header, int aac_length)
{
    /**
     * 0: 96000Hz
     * 3: 48000Hz
     * 4: 44100Hz
     */
    byte freq_index = 0;

    switch (ctx->sample_rate) {
        case 96000:
            freq_index = 0;
            break;
        case 88200:
            freq_index = 1;
            break;
        case 64000:
            freq_index = 2;
            break;
        case 48000:
            freq_index = 3;
            break;
        case 44100:
            freq_index = 4;
            break;
        case 32000:
            freq_index = 5;
            break;
        case 24000:
            freq_index = 6;
            break;
        case 22050:
            freq_index = 7;
            break;
        case 16000:
            freq_index = 8;
            break;
        case 12000:
            freq_index = 9;
            break;
        case 11025:
            freq_index = 10;
            break;
        case 8000:
            freq_index = 11;
            break;
        case 7350:
            freq_index = 12;
            break;
        default:
            freq_index = 4;
            break;
    }

    byte chanCfg = ctx->channels;
    uint frame_length = aac_length + 7;
    adts_header[0] = 0xFF;
    adts_header[1] = 0xF1;
    adts_header[2] = ((ctx->profile) << 6) + (freq_index << 2) + (chanCfg >> 2);
    adts_header[3] = (((chanCfg & 3) << 6) + (frame_length >> 11));
    adts_header[4] = ((frame_length & 0x7FF) >> 3);
    adts_header[5] = (((frame_length & 7) << 5) + 0x1F);
    adts_header[6] = 0xFC;
}