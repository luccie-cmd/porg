#include "Compiler.h"

Compiler compiler_create(TokenList tl){
    Compiler cm;
    cm.bb = bb_create(1);
    cm.tl = tl;
    cm.status = COMPILER_SUCCES;
    return cm;
}

void cm_compile(Compiler cm){
    for(int tokI = 0; tokI < cm.tl.tok_len; ++tokI){
        switch(cm.tl.tokens[tokI].type){
            case TT_INST: {
                switch(cm.tl.tokens[tokI].data){
                    case INST_SET: {
                        if(cm.tl.tokens[tokI + 1].type == TT_REGISTER && cm.tl.tokens[tokI + 2].type == TT_NUMBER){
                            bb_write8(&cm.bb, OP_SET);
                            bb_write8(&cm.bb, cm.tl.tokens[tokI+1].data);
                            bb_write8(&cm.bb, cm.tl.tokens[tokI+2].data);
                        }
                        else{
                            printf("Bad set INST\n");
                            cm.status = COMPILER_SYNTAXERROR;
                        }
                    } break;
                    case INST_PRINT: {
                        if(cm.tl.tokens[tokI + 1].type == TT_REGISTER){
                            bb_write8(&cm.bb, OP_PRINT);
                            bb_write8(&cm.bb, cm.tl.tokens[tokI+1].data);
                        }
                        else{
                            printf("Bad print INST\n");
                            cm.status = COMPILER_SYNTAXERROR;
                        }
                    } break;
                    case INST_SUM: {
                        if(cm.tl.tokens[tokI + 1].type == TT_REGISTER && cm.tl.tokens[tokI + 2].type == TT_REGISTER){
                            bb_write8(&cm.bb, OP_SUM);
                            bb_write8(&cm.bb, cm.tl.tokens[tokI+1].data);
                            bb_write8(&cm.bb, cm.tl.tokens[tokI+2].data);
                        }
                        else{
                            printf("Bad sum INST\n");
                            cm.status = COMPILER_SYNTAXERROR;
                        }
                    } break;
                }
            } break;
        }
    }
    cm.status = COMPILER_SUCCES;
    bb_print(cm.bb);
}