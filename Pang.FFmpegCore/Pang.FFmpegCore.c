﻿// Pang.FFmpegCore.cpp: 定义应用程序的入口点。
//

#include "Pang.FFmpegCore.h"


int main()
{
	enum AVCodecID id = AV_CODEC_ID_AAC;
	enum AudioType tp = AUDIO_TYPE_PCM;

	printf("%s\n", pffc_get_audio_type_name(tp));
	printf("%d\n", pffc_get_audio_type_size());

	printf("Hello World\n");
	return 0;
}
