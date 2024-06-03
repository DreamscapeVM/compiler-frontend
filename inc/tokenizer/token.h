#ifndef __INCLUDE_TOKENIZER_TOKEN_H
#define __INCLUDE_TOKENIZER_TOKEN_H

#include <cstdint>

enum class token : uint8_t { 
    error,           // for NULL
    eof,             // success and work done.
    operand,         // +, -, *, /
    name,            // name of func, parm or var
    something_start, // ;
    define_constant, // num
    start_data_type, // :
    array,           // [, ]
    reserved_word,   // while, for, if, etc ...
    comment,         // # comment
};

#endif // __INCLUDE_TOKENIZER_TOKEN_H
