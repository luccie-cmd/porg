#include <stdio.h>
#include "Util.h"
#include "Token.h"

int main(int argc, char** argv){
    if(argc != 2){
        printf("Too many or little arguments for porgo\nyou only need to specify the path to the file\n");
        exit(1);
    }
    // skip the program
    shift(&argc, &argv);
    char* file = NULL;
    while(argc > 0){
        file = shift(&argc, &argv);
    }
    ByteBuffer bb = bb_create(1);
    readBinFile(file, bb);
    bb_print(bb);
    int i = 0;
    while(bb.buffer[i] != OP_HLT){
        switch (bb.buffer[i++]){
            case OP_SET: {
                int Register = bb.buffer[i++];
                int Number   = bb.buffer[i++];
                registers[Register] = Number;
            } break;
            case OP_PRINT: {
                int Register = bb.buffer[i++];
                printf("%d\n", registers[Register]);
            } break;
            case OP_SUM: {
                int Register1 = bb.buffer[i++];
                int Register2 = bb.buffer[i++];
                registers[Register1] += registers[Register2];
            } break;
            case OP_SUB: {
                int Register1 = bb.buffer[i++];
                int Register2 = bb.buffer[i++];
                registers[Register1] -= registers[Register2];
            } break;
            case OP_MUL: {
                int Register1 = bb.buffer[i++];
                int Register2 = bb.buffer[i++];
                registers[Register1] *= registers[Register2];
            } break;
        }
    }
    return 0;
}