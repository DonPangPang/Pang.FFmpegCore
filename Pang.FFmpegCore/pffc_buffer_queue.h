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

int pffc_get_buffer_queue_size();

void pffc_buffer_queue_enqueue_array(byte[], int);

void pffc_buffer_queue_enqueue_array_pointer(byte*, int);

byte* pffc_buffer_queue_dequeue_array(int);

// TODO: 函数声明

int pffc_get_buffer_queue_size()
{
    return buffer_queue.size;
}

void pffc_buffer_queue_enqueue_array(byte input[], int in_size)
{

}

void pffc_buffer_queue_enqueue_array_pointer(byte* input, int in_size)
{

}

byte* pffc_buffer_queue_dequeue_array(int out_size)
{
    
}

#endif // !__PFFC_BUFFER_QUEUE_H__
