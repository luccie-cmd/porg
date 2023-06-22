#include "Lexer.h"

TokenList lexInit(const char *path){
    char* src = readFile(path);
    char* lex = (char*)malloc(256);
    int srci = 0;
    int lexi = 0;
    TokenList list = Maketokenlist(1);
    while(1){
        while(src[srci] != ' ' && src[srci] != '\n' && src[srci] != '\0'){
            lex[lexi++] = src[srci++];
        }
        if(src[srci] == '\n' && lexi == 1){
            srci++;
            lexi = 0;
            continue;
        }
        lex[lexi++] = '\0';
        parseLex(lex, &list);
        if(src[srci] == '\0'){
            break;
        }
        // Skip the space or newline character
        srci++;
        lexi = 0;
    }
    return list;
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
    } else if(strcmp(lex, "sub") == 0){
        tok = Maketoken(TT_INST, INST_SUB);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else if(strcmp(lex, "mul") == 0){
        tok = Maketoken(TT_INST, INST_MUL);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else if(strcmp(lex, "inc") == 0){
        tok = Maketoken(TT_INST, INST_INC);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else if(strcmp(lex, "dec") == 0){
        tok = Maketoken(TT_INST, INST_DEC);
        addToTokenList(list, tok); // Implement addToTokenList correctly
    } else if(strcmp(lex, "hlt") == 0){
        tok = Maketoken(TT_INST, INST_HLT);
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
    chopLastChar(lex);
    tok = Maketoken(TT_REGISTER, getRegisterFromName(lex));
    addToTokenList(list, tok);
}
void parserHandleNumber(char* lex, Token tok, TokenList *list){
    chopFirstChar(lex);
    tok = Maketoken(TT_NUMBER, getNumberFromName(lex));
    addToTokenList(list, tok);
}