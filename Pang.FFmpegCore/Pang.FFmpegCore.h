// Pang.FFmpegCore.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#pragma warning (disable:4879 4090 4819 4477)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: 宏定义
#define byte uint8_t
#define ulong uint64_t
#define uint uint32_t

#define bool int
#define boolean int

#define TRUE 1
#define true 1
#define FALSE 0
#define false 0 

// TODO: 在此处引用程序需要的其他标头。

#include <libavcodec/avcodec.h>

#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/frame.h>
#include <libavutil/samplefmt.h>
#include <libavutil/opt.h>
#include <libswresample/swresample.h>

// TODO: 自定义头文件
#include "pffc_enum.h"
#include "pffc_structs.h"
#include "pffc_helper.h"
#include "pffc_buffer_queue.h"

#include "pffc_converter.h"
#include "pffc_encoder.h"



