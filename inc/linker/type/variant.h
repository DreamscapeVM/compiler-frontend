#ifndef __INCLUDE_LINKER_TYPE_VARIANT_H
#define __INCLUDE_LINKER_TYPE_VARIANT_H

#include <string>
#include <vector>

namespace linker { 

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
    
    array_uint8,    // w/ pointer
    array_uint16,   // w/ pointer
    array_uint32,   // w/ pointer
    array_uint64,   // w/ pointer

    array_int8,     // w/ pointer
    array_int16,    // w/ pointer
    array_int32,    // w/ pointer
    array_int64,    // w/ pointer

    array_float8,   // w/ pointer
    array_float16,  // w/ pointer
    array_float32,  // w/ pointer
    array_float64,  // w/ pointer

    string,         // w/ pointer
};



struct variant { 
    variant_type type; // maybe not used.
    std::string name;  // identifier
    std::vector<uint8_t> data; // with size of var
};

}

#endif // __INCLUDE_LINKER_TYPE_VARIANT_H
