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


void init_converter(AVCodecContext* codec_ctx, ulong source_ch_layout, enum AVSampleFormat source_sample_fmt, int source_sample_rate)
{

}

byte *pcm_s16le_convert_to_fltp(byte input[])
{
    return NULL;
}

#endif // !__PFFC_CONVERTER_H__