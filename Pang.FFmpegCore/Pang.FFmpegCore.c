// Pang.FFmpegCore.cpp: 定义应用程序的入口点。
//

#include "Pang.FFmpegCore.h"
#include "audio_enum.h"


int main()
{
	enum AVCodecID id = AV_CODEC_ID_AAC;
	enum AudioType tp = AUDIO_TYPE_PCM;

	printf("Hello World");
	Hello();
	return 0;
}
