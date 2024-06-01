#ifndef __INCLUDE_LINKER_TYPE_FUNCTION_H
#define __INCLUDE_LINKER_TYPE_FUNCTION_H

#include <string>
#include <vector>
#include <tuple>
#include <vector>

#include <linker/type/variant.h>

namespace linker { 

struct function { 
    variant_type ret; // maybe not used.
    std::string name;  // identifier

    std::vector<std::tuple<std::string, variant_type>> arg;
    std::vector<uint8_t> data;
};

}

#endif // __INCLUDE_LINKER_TYPE_FUNCTION_H
