#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "INSTS.h"

typedef struct Token{
    int type;
    int data;
} Token;
typedef struct TokenList{
    Token* tokens;
    int tok_len;
    int malloc_len;
} TokenList;

Token Maketoken(int type, int data);
TokenList Maketokenlist(int len);
void addToTokenList(TokenList* tokenlist, Token tok);
void printToken(Token tok);
void printTokenList(TokenList list);