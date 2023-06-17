#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct Token{
    int type;
    int data;
} Token;
typedef struct TokenList{
    Token* tokens;
    int tok_len;
    int malloc_len;
} TokenList;
enum TokenTypes{
    TT_NONE=0,
    TT_INST,
    TT_NUMBER,
    TT_REGISTER,
};
enum TokenInsts{
    INST_NONE,
    INST_SET,
    INST_PRINT,
};

Token Maketoken(int type, int data);
TokenList Maketokenlist(int len);
void addToTokenList(TokenList* tokenlist, Token tok);
void printToken(Token tok);
void printTokenList(TokenList list);