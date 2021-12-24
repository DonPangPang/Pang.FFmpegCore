#pragma once

#ifndef __PFFC_STRUCTS_H__
#define __PFFC_STRUCTS_H__

#include "Pang.FFmpegCore.h"

struct ConvertAudio;
struct EncodeAudio;
struct AudioBuffer;

/**
 * @brief 重采样后的数据
 * 
 */
struct ConvertAudioPacket
{
    byte* data;
    int size;
} ConvertAudioPacket;

struct EncodeAudio
{
    byte* data;
    int size;
} EncodeAudioPacket;

struct AudioBuffer
{
    byte* data;
    int size;
} AudioBuffer;


#endif // !__PFFC_STRUCTS_H__