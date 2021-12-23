#pragma once

#ifndef __PFFC_STRUCTS_H__
#define __PFFC_STRUCTS_H__

#include "Pang.FFmpegCore.h"

struct ConvertAudio;

/**
 * @brief 重采样后的数据
 * 
 */
struct ConvertAudioPacket
{
    uint8_t* data;
    int size;
} ConvertAudioPacket;

#endif // !__PFFC_STRUCTS_H__