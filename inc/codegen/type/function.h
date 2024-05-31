#ifndef __INCLUDE_CODEGEN_TYPE_FUNCTION_H
#define __INCLUDE_CODEGEN_TYPE_FUNCTION_H

#include <string>
#include <vector>
#include <tuple>
#include <vector>

#include <codegen/type/variant.h>

namespace codegen { 

struct function { 
    variant_type ret; // maybe not used.
    std::string name;  // identifier

    std::vector<std::tuple<std::string, variant_type>> arg;
    std::vector<uint8_t> data;
};

}

#endif // __INCLUDE_CODEGEN_TYPE_FUNCTION_H
