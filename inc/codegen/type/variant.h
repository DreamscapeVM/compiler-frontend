#ifndef __INCLUDE_CODEGEN_TYPE_VARIANT_H
#define __INCLUDE_CODEGEN_TYPE_VARIANT_H

#include <string>
#include <vector>

namespace codegen { 

enum class variant_type : uint8_t { 
    none,

    uint8,
    uint16,
    uint32,
    uint64,

    int8,
    int16,
    int32,
    int64,
    
    float8,
    float16,
    float32,
    float64,
    
    array_uint8,
    array_uint16,
    array_uint32,
    array_uint64,

    array_int8,
    array_int16,
    array_int32,
    array_int64,

    array_float8,
    array_float16,
    array_float32,
    array_float64,

    string,
};

struct variant { 
    variant_type type; // maybe not used.
    std::string name;  // identifier
    int size;
    std::vector<uint8_t> data;
};

}

#endif // __INCLUDE_CODEGEN_TYPE_VARIANT_H
