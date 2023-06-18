#include "ByteBuffer.h"

ByteBuffer bb_create(int size){
    ByteBuffer bb;
    bb.buffer = (uint8_t*)malloc(size);
    bb.malloc_len = size;
    bb.buffer_len = 0;
    return bb;
}

void bb_write8(ByteBuffer *bb, uint8_t data){
    if (bb->malloc_len >= bb->buffer_len){
		bb->malloc_len *= 2;
		bb->buffer = (uint8_t*)realloc(bb->buffer, sizeof(uint8_t) * (bb->buffer_len+1));
	}
	bb->buffer[bb->buffer_len++] = data;
    // printf("%u\n", bb->buffer[bb->buffer_len]);
}

void bb_print(ByteBuffer bb){
    for(int i = 0; i < bb.buffer_len; ++i){
        printf("%d\n", bb.buffer[i]);
    }
}
