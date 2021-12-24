/**
 * @file pffc_enum.h
 * @author Powers (powertle@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 * 对于音频格式的枚举
 */

#pragma once

#ifndef __PFFC_ENUM_H__
#define __PFFC_ENUM_H__

#include "Pang.FFmpegCore.h"

enum AudioType;

const int audio_types_size = 3;

const byte* audio_types[] = 
{
	"pcm", "aac", "mp3", "not found"
};

enum AudioType
{
	AUDIO_TYPE_PCM = 0,
	AUDIO_TYPE_AAC = 1,
	AUDIO_TYPE_MP3 = 2
} AudioType;

/**
 * @brief Get the audio type name object
 * 
 * @param audio 
 * @return byte* 
 */
byte *pffc_get_audio_type_name(enum AudioType audio);

int pffc_get_audio_type_size();

int pffc_get_audio_type_size()
{
	return audio_types_size;
}

/**
 * @brief Get the audio type name object
 * 
 * @param audio 
 * @return byte* 
 */
byte *pffc_get_audio_type_name(enum AudioType audio)
{
	if(audio >= audio_types_size)
	{
		return audio_types[pffc_get_audio_type_size()];
	}
	return audio_types[audio];
}

#endif // ! __PFFC_ENUM_H__
