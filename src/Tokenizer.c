#include "Tokenizer.h"

void TokenizerHandleTokenlist(TokenList list){
    for(int tokI = 0; tokI < list.tok_len; ++tokI){
        switch(list.tokens[tokI].type){
            case TT_INST: {
                switch(list.tokens[tokI].data){
                    case INST_SET: {
                        int Register = -1;
                        int Number = -1;
                        if(list.tok_len < 3){
                            printf("Not enough oprands for inst `set`\n");
                            exit(1);
                        }
                        if(list.tokens[tokI+1].type == TT_REGISTER && list.tokens[tokI+2].type == TT_NUMBER){
                            Register = list.tokens[tokI+1].data;
                            Number = list.tokens[tokI+2].data;
                            registers[Register] = Number;
                        }
                        else{
                            printf("Inst set not good\n");
                            printf("Set inst syntax is:\n");
                            printf("    set [REGISTER] <NUMBER>\n");
                            printf("Registers are:\n");
                            printf("    eax ebx ecx edx\n");
                            printf("numbers are tokens that start with #\n");
                            exit(1);
                        }
                    } break;
                    case INST_PRINT: {
                        int Register = -1;
                        if(list.tok_len < 2){
                            printf("Not enough oprands for inst `print`\n");
                            exit(1);
                        }
                        if(list.tokens[tokI+1].type == TT_REGISTER){
                            Register = list.tokens[tokI+1].data;
                            printf("%d\n", registers[Register]);
                        }
                        else{
                            printf("Inst print not good\n");
                            printf("Print inst syntax is:\n");
                            printf("    print [REGISTER]\n");
                            printf("Registers are:\n");
                            printf("    eax ebx ecx edx\n");
                            exit(1);
                        }
                    } break;
                    case INST_SUM: {
                        int Register1 = -1;
                        int Register2 = -1;
                        if(list.tok_len < 3){
                            printf("Not enough oprands for inst `sum`\n");
                            exit(1);
                        }
                        if(list.tokens[tokI+1].type == TT_REGISTER && list.tokens[tokI+2].type == TT_REGISTER){
                            Register1 = list.tokens[tokI+1].data;
                            Register2 = list.tokens[tokI+2].data;
                            registers[Register1] += registers[Register2];
                        }
                        else{
                            printf("Inst sum not good\n");
                            printf("Sum inst syntax is:\n");
                            printf("    sum [REGISTER1/DST] [REGISTER2/SRC]\n");
                            printf("Registers are:\n");
                            printf("    eax ebx ecx edx\n");
                            exit(1);
                        }
                    } break;
                }
            } break;
        }
    }
}