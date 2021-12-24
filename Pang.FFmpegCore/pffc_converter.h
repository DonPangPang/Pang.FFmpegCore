/**
 * @file pffc_converter.h
 * @author Powers (powertle@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#ifndef __PFFC_CONVERTER_H__
#define __PFFC_CONVERTER_H__

#include "Pang.FFmpegCore.h"

void init_converter(AVCodecContext *, ulong, enum AVSampleFormat, int);

/**
 * @brief pcm s16le to fltp
 * 
 * @return byte* 
 */
byte *pcm_s16le_convert_to_fltp(byte[]);

/**
 * @brief pcm s16le to fltp
 * 
 * @return byte* 
 */
byte *pcm_s16le_convert_to_fltp2(byte *);

/**
 * @brief 释放资源
 * 
 */
void dispose_converter();

SwrContext *swr_ctx_g;

void init_converter(AVCodecContext *codec_ctx, ulong source_ch_layout, enum AVSampleFormat source_sample_fmt, int source_sample_rate)
{
    swr_ctx_g = swr_alloc();
    if (!swr_ctx_g)
    {
        fprintf(stderr, "Could not allocate swr_context.\n");
        exit(1);
    }

    swr_ctx_g = swr_alloc_set_opts(swr_ctx_g,
                                   codec_ctx->channel_layout,
                                   codec_ctx->sample_fmt,
                                   codec_ctx->sample_rate,
                                   source_ch_layout,
                                   source_sample_fmt,
                                   source_sample_rate, 0, 0);

    if(swr_init(swr_ctx_g) < 0)
    {
        fprintf(stderr, "Could not init swr_context.\n");
        exit(1);
    }
}

byte *pcm_s16le_convert_to_fltp(byte input[])
{
    return NULL;
}

byte *pcm_s16le_convert_to_fltp2(byte *input)
{
}

void dispose_converter()
{
}

#endif // !__PFFC_CONVERTER_H__