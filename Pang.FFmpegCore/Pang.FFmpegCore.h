// Pang.FFmpegCore.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once
#pragma warning (disable:4879 4090 4819)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// TODO: 宏定义
#define byte uint8_t

// TODO: 在此处引用程序需要的其他标头。

#include <libavcodec/avcodec.h>

#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/frame.h>
#include <libavutil/samplefmt.h>
#include <libavutil/opt.h>

// TODO: 自定义头文件
#include "pffc_converter.h"
#include "pffc_encoder.h"
#include "pffc_enum.h"
#include "pffc_structs.h"

