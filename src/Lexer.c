#include "Lexer.h"

void lexInit(const char *path){
    char* src = readFile(path);
    char* lex = (char*)malloc(256);
    int srci = 0;
    int lexi = 0;
    TokenList list = Maketokenlist(1);
    while(1){
        while(src[srci] != ' ' && src[srci] != '\n' && src[srci] != '\0'){
            lex[lexi++] = src[srci++];
        }
        lex[lexi++] = '\0';
        parseLex(lex, &list);
        if(src[srci] == '\0'){
            break;
        }
        srci++; // get rid of the space or the new line
        lexi = 0; // reset lexi for new itteration
    }
    TokenizerHandleTokenlist(list);
}

void parseLex(char* lex, TokenList *list){
    Token tok = Maketoken(TT_NONE, INST_NONE);
    if(strcmp(lex, "set") == 0){
        tok = Maketoken(TT_INST, INST_SET);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else if(strcmp(lex, "print") == 0){
        tok = Maketoken(TT_INST, INST_PRINT);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else if(strcmp(lex, "sum") == 0){
        tok = Maketoken(TT_INST, INST_SUM);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else{
        if(lex[0] == '%') parserHandleRegister(lex, tok, list); // Call the register handling function if needed
        else if(lex[0] == '#') parserHandleNumber(lex, tok, list); // handle the number
        else{
            printf("Invalid token `%s`\n", lex);
            exit(1);
        }
    }
}

void parserHandleRegister(char* lex, Token tok, TokenList *list){
    chopFirstChar(lex);
    chopLastCharOfRegister(lex);
    tok = Maketoken(TT_REGISTER, getRegisterFromName(lex));
    addToTokenList(list, tok);
}
void parserHandleNumber(char* lex, Token tok, TokenList *list){
    chopFirstChar(lex);
    tok = Maketoken(TT_NUMBER, getNumberFromName(lex));
    addToTokenList(list, tok);
}