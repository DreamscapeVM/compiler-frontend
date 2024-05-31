#ifndef __INCLUDE_CODEGEN_GEN_H
#define __INCLUDE_CODEGEN_GEN_H

#include <string>
#include <vector>
#include <codegen/type/variant.h>
#include <codegen/type/convert_type_to_varianttype.h>

namespace codegen {
class linker
{
private:
    std::vector<variant> var;

    void add_var(std::string name, void* pos, int size) { 
        // variant { 
        //     .name = name,
        //     .size = size,
        // };
    }

public:
    template<typename T>
    void add_var(std::string name, const T value) { 
        auto size = sizeof(T); 
    }
    template<>
    void add_var(std::string name, const std::string value) { 
        auto size = value.size() + 1; // size + 1, because of null
    }
};


}

#endif
