#pragma once
#include "ByteBuffer.h"
#include "Token.h"
#include "REGISTERS.h"
#include "Util.h"

typedef struct Compiler{
    ByteBuffer bb;
    TokenList tl;
    int status;
} Compiler;

enum CompilerStatus{
    COMPILER_SUCCES=0,
    COMPILER_SYNTAXERROR=1,
};

Compiler compiler_create(TokenList tl);
void cm_compile(Compiler cm, const char* out_file);