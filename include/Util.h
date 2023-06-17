#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum registerNames{
    REG_EAX=0,
    REG_EBX,
    REG_ECX,
    REG_EDX,
};
extern int registers[4];

char* readFile(const char* path);
int getRegisterFromName(char* name);
int getNumberFromName(char* name);
void chopFirstChar(char* str);
void chopLastCharOfRegister(char* str);