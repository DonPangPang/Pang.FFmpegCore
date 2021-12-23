# CMakeList.txt: Pang.FFmpegCore 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

include_directories(../include)

link_directories(../lib)

# 将源代码添加到此项目的可执行文件。
add_executable (Pang.FFmpegCore "Pang.FFmpegCore.c" "Pang.FFmpegCore.h")

# target_link_libraries(Pang.FFmpegCore avcodec-58 avdevice-58 avfilter-7 avformat-58 avitil-56 postproc-55 swresample-3 swscale-5)
target_link_libraries(Pang.FFmpegCore avcodec avdevice avfilter avformat avutil postproc swresample swscale)

# TODO: 如有需要，请添加测试并安装目标。
