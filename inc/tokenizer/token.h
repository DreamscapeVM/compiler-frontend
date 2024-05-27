#ifndef __INCLUDE_TOKENIZER_TOKEN_H
#define __INCLUDE_TOKENIZER_TOKEN_H

enum class token { 
    operand,
    name,
    something_start,
    define_constant,
    define_variable_mutable,
    define_variable_unmutable,
    start_data_type,
    data_type,
    start_array,
    end_array
};

#endif // __INCLUDE_TOKENIZER_TOKEN_H
