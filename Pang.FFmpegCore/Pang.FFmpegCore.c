// Pang.FFmpegCore.cpp: 定义应用程序的入口点。
//

#include "Pang.FFmpegCore.h"


int main()
{
	enum AVCodecID id = AV_CODEC_ID_AAC;
	enum AudioType tp = AUDIO_TYPE_PCM;

	printf("Hello World\n");

	int a = 6;
	int* p = &a;
	int res = *p * *p;
	printf("%d", res);
	return 0;
}
