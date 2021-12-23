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

#ifndef AUDIO_ENUM_H
#define AUDIO_ENUM_H

#include <stdio.h>

enum AudioType;

enum AudioType
{
	AUDIO_TYPE_PCM,
	AUDIO_TYPE_AAC,
	AUDIO_TYPE_MP3
} AudioType;


#endif // ! AUDIO_ENUM_H
