#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "../../porg/include/REGISTERS.h"
#include "../../porg/include/ByteBuffer.h"

char* readFile(const char* path);
void readBinFile(const char* file, ByteBuffer bb);

void writeBinFile(const char* file, ByteBuffer bb);
int getRegisterFromName(char* name);
int getNumberFromName(char* name);
void chopFirstChar(char* str);
void chopLastCharOfRegister(char* str);
char* shift(int *argc, char*** argv);