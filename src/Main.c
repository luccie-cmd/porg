#include <stdio.h>
#include <stdlib.h>
#include "Lexer.h"
#include <assert.h>

// used from https://github.com/tsoding/bm/blob/master/common/path.c line: 119
char* shift(int* argc, char*** argv){
    assert(*argc > 0);
    char *result = **argv;
    *argv += 1;
    *argc -= 1;
    return result;
}

int main(int argc, char** argv){
    const char* const program = argv[0];
    if(argc < 2){
        printf("Not enough parameters for `%s`\n", program);
        exit(1);
    }
    // skip the program
    shift(&argc, &argv);

    // get the first flag aka program
    char* file = shift(&argc, &argv);
    lexInit(file);
    return 0;
}