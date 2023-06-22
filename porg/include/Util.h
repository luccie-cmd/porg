#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "REGISTERS.h"
#include "ByteBuffer.h"

char* readFile(const char* path);
uint8_t* readBinFile(const char* file);

void writeBinFile(const char* file, ByteBuffer bb);
int getRegisterFromName(char* name);
int getNumberFromName(char* name);
void chopFirstChar(char* str);
void chopLastChar(char* str);
char* shift(int *argc, char*** argv);