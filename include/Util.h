#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "REGISTERS.h"

char* readFile(const char* path);
int getRegisterFromName(char* name);
int getNumberFromName(char* name);
void chopFirstChar(char* str);
void chopLastCharOfRegister(char* str);