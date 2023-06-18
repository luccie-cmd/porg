#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lexer.h"
#include "Token.h"
#include "Tokenizer.h"

// used from https://github.com/tsoding/bm/blob/master/common/path.c line: 119
char* shift(int* argc, char*** argv){
    assert(*argc > 0);
    char *result = **argv;
    *argv += 1;
    *argc -= 1;
    return result;
}

void usage(const char* const program){
    printf("%s [OPTIONS]\n", program);
    printf("options are:\n");
    printf("    -h      print this help\n");
    printf("    -i      run your program without compiling\n");
    printf("    -c      compile your program\n");
}

int main(int argc, char** argv){
    const char* const program = argv[0];
    if(argc < 2){
        printf("Not enough parameters for `%s`\n", program);
        exit(1);
    }
    // skip the program
    shift(&argc, &argv);
    bool compile = false;
    bool interpret = false;
    char* file = NULL;
    while(argc > 0){
        char* flag = shift(&argc, &argv);
        if(strcmp(flag, "-c") == 0 && !interpret){
            compile = true;
        } else if(strcmp(flag, "-i") == 0 && !compile){
            interpret = true;
        } else if(strcmp(flag, "-h") == 0){
            usage(program);
            exit(0);
        } else{
            file = flag;
        }
    }
    TokenList lexList = lexInit(file);
    // TokenizerHandleTokenlistI(lexList);
    if(compile){
        TokenizerHandleTokenlistC(lexList);
    }
    else if(interpret){
        TokenizerHandleTokenlistI(lexList);
    }
    else{
        assert(false && "No valid opperation specified options are -i for interpret and -c for compile");
    }
    return 0;
}