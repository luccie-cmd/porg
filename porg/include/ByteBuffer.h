#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct ByteBuffer{
    uint8_t* buffer;
    int malloc_len;
    int buffer_len;
} ByteBuffer;

ByteBuffer bb_create(int size);
void bb_write8(ByteBuffer* bb, uint8_t data);
void bb_print(ByteBuffer bb);