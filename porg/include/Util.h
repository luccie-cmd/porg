#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "REGISTERS.h"
#include "ByteBuffer.h"

char* readFile(const char* path);
void writeBinFile(const char* file, ByteBuffer bb);
int getRegisterFromName(char* name);
int getNumberFromName(char* name);
void chopFirstChar(char* str);
void chopLastCharOfRegister(char* str);