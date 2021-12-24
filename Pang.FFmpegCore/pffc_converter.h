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

/**
 * @brief 用来转码PCM
 * 
 * @return struct ConvertAudioPacket* 
 */
struct ConvertAudioPacket* pffc_pcm_audio_convert(byte[]);

/**
 * @brief 用来转码PCM
 * 
 * @param buffer 
 * @return struct ConvertAudioPacket* 
 */
struct ConvertAudioPacket* pffc_pcm_audio_convert(byte buffer[])
{
    return NULL;
}

#endif // !__PFFC_CONVERTER_H__