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
};