#pragma once

#ifndef __PFFC_STRUCTS_H__
#define __PFFC_STRUCTS_H__

#include "Pang.FFmpegCore.h"

struct ConvertAudio;

/**
 * @brief 返回数据结构体
 * 
 */
struct ConvertAudio
{
    uint8_t* data;
    int size;
} AudioBlock;

#endif // !__PFFC_STRUCTS_H__