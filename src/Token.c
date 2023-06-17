#include "Token.h"

Token Maketoken(int type, int data){
    return (Token){.type = type, .data = data};
}

TokenList Maketokenlist(int len){
    TokenList list;
    list.tokens = (Token*)malloc(sizeof(Token) * len);
    list.tok_len = 0;
    list.malloc_len = len;
    return list;
}

void addToTokenList(TokenList *list, Token tok){
    if (list->malloc_len >= list->tok_len){
		list->malloc_len *= 2;
		list->tokens = (Token*) realloc(list->tokens, sizeof(Token) * (list->tok_len+1));
	}
	list->tokens[list->tok_len++] = tok;
}

void printToken(Token tok){
    printf("type = %d data = %d\n", tok.type, tok.data);
}

void printTokenList(TokenList list){
    for(int i = 0; i < list.tok_len; ++i){
        printToken(list.tokens[i]);
    }
}
