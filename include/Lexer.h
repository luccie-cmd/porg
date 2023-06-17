#pragma once
#include <stdlib.h>
#include <string.h>
#include "Token.h"
#include "Util.h"
#include "Tokenizer.h"

TokenList lexInit(const char* path);
void parseLex(char* lex, TokenList *list);
void parserHandleRegister(char* lex, Token tok, TokenList* list);
void parserHandleNumber(char* lex, Token tok, TokenList* list);