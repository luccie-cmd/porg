#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Lexer.h"
#include "Token.h"
#include "Tokenizer.h"
#include "Compiler.h"
#include "Util.h"

void usage(){
    printf("porg [OPTIONS]\n");
    printf("options are:\n");
    printf("    -h        print this help\n");
    printf("    -i        run your program without compiling\n");
    printf("    -c        compile your program\n");
    printf("    -o [FILE] set output file to FILE (only recommended for flag `-c`)\n");
}

int main(int argc, char** argv){
    const char* const program = argv[0];
    // skip the program
    shift(&argc, &argv);
    if(argc == 0){
        usage();
        exit(1);
    }
    bool compile = false;
    bool interpret = false;
    char* in_file = NULL;
    char* out_file = NULL;
    while(argc > 0){
        char* flag = shift(&argc, &argv);
        // printf("%s\n", flag);
        if(strcmp(flag, "-c") == 0 && !interpret){
            compile = true;
            in_file = shift(&argc, &argv);
        } else if(strcmp(flag, "-i") == 0 && !compile){
            interpret = true;
            in_file = shift(&argc, &argv);
        } else if(strcmp(flag, "-h") == 0){
            usage(program);
            exit(0);
        } else if(strcmp(flag, "-o") == 0){
            out_file = shift(&argc, &argv);
        } else{
            in_file = flag;
        }
    }
    TokenList lexList = lexInit(in_file);
    if(compile){
        Compiler cm = compiler_create(lexList);
        cm_compile(cm, out_file);
    }
    else if(interpret){
        TokenizerHandleTokenlistI(lexList);
    }
    else{
        assert(false && "No valid opperation specified options are -i for interpret and -c for compile");
    }
    return 0;
}