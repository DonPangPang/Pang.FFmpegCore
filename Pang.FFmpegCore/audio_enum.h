/**
 * @file audio_enum.h
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
#pragma warning (disable:4879 4090)

#ifndef __AUDIO_ENUM_H__
#define __AUDIO_ENUM_H__

#include <stdio.h>
#include <string.h>

enum AudioType;

const int audio_types_size = 3;

const char* audio_types[] = 
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
 * @return char* 
 */
char *get_audio_type_name(enum AudioType audio);

int get_audio_type_size()
{
	return audio_types_size;
}

/**
 * @brief Get the audio type name object
 * 
 * @param audio 
 * @return char* 
 */
char *get_audio_type_name(enum AudioType audio)
{
	if(audio >= audio_types_size)
	{
		return audio_types[get_audio_type_size()];
	}
	return audio_types[audio];
}

#endif // ! AUDIO_ENUM_H
