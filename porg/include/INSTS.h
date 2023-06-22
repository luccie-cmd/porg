#pragma once
enum TokenTypes{
    TT_NONE=0,
    TT_INST,
    TT_NUMBER,
    TT_REGISTER,
};
enum TokenInsts{
    INST_NONE,
    INST_SET,
    INST_PRINT,
    INST_SUM,
    INST_SUB,
    INST_MUL,
    INST_HLT,
};
enum OPS{
    OP_SET=0x01,
    OP_PRINT=0x02,
    OP_SUM=0x03,
    OP_SUB=0x04,
    OP_MUL=0x05,
    OP_HLT=0xFF,
};