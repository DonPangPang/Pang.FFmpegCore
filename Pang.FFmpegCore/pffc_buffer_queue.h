/**
 * @file pffc_buffer_queue.h
 * @author Powers (powertle@outlook.com)
 * @brief 作为缓冲区使用
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#ifndef __PFFC_BUFFER_QUEUE_H__
#define __PFFC_BUFFER_QUEUE_H__

#include "Pang.FFmpegCore.h"

struct AudioBuffer buffer_queue = {NULL, 0};

// TODO: 函数声明

/**
 * @brief 获取缓冲区的长度
 * 
 * @return int 
 */
int pffc_get_buffer_queue_size();

/**
 * @brief 写入缓冲区
 * 
 */
void pffc_buffer_queue_enqueue_array(byte[], int);

/**
 * @brief 写入缓冲区
 * 
 */
void pffc_buffer_queue_enqueue_array_pointer(byte*, int);

/**
 * @brief 读出缓冲区
 * 
 * @return byte* 读出的数据
 */
byte* pffc_buffer_queue_dequeue_array(int);

// TODO: 函数声明

int pffc_get_buffer_queue_size()
{
    return buffer_queue.size;
}

void pffc_buffer_queue_enqueue_array(byte input[], int in_size)
{
    int size = buffer_queue.size;
    for(int i = 0; i < in_size; i++)
    {
        buffer_queue.data[size + i] = input[i];
        buffer_queue.data++;
    }
    buffer_queue.size += in_size;
}

void pffc_buffer_queue_enqueue_array_pointer(byte* input, int in_size)
{
    int size = buffer_queue.size;
    for(int i = 0; i < in_size; i++)
    {
        buffer_queue.data[size + i] = input[i];
        buffer_queue.data++;
    }
    buffer_queue.size += in_size;
}

byte* pffc_buffer_queue_dequeue_array(int out_size)
{
    byte* output = NULL;
    for (int i = 0; i < out_size; i++)
    {
        output[i] = buffer_queue.data[i];
        output++;
    }
    buffer_queue.data += out_size;
    buffer_queue.size -= out_size;

    return output;
}

#endif // !__PFFC_BUFFER_QUEUE_H__
