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

struct ConvertAudioPacket* pffc_pcm_audio_convert(byte[]);

struct ConvertAudioPacket* pffc_pcm_audio_convert(byte buffer[])
{
    return NULL;
}

#endif // !__PFFC_CONVERTER_H__