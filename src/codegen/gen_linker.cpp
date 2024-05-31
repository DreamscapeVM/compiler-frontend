#include <sstream>
#include <codegen/linker.h>
#include <codegen/type/convert_varianttype_to_size.h>

const std::vector<codegen::variant>* const codegen::linker::get_variant() const { 
    return &var;
}
const std::vector<codegen::function>* const codegen::linker::get_function() const { 
    return &func;
}

std::vector<uint8_t> codegen::linker::convert_var_to_bin(const codegen::variant& v) const { 
    std::vector<uint8_t> output;
    output.push_back(0); // var type define
    output.push_back(v.name.size()); // var name
    for (int i = 0; i < v.name.size(); i++) { 
        output.push_back(v.name[i]);
    }
    auto s = (int32_t)v.data.size();
    for (int i = 0; i < 4; i++) { 
        auto d = ((uint8_t*)&s)[i];
        output.push_back(d);
    }
    
    for (int i = 0; i < s; i++) { 
        output.push_back(v.data[i]);
    }

    return output;
}

std::vector<uint8_t> codegen::linker::convert_func_to_bin(const codegen::function& f) const { 
    std::vector<uint8_t> output;
    output.push_back(1); // var type define
    output.push_back(f.name.size()); // func name
    for (int i = 0; i < f.name.size(); i++) { 
        output.push_back(f.name[i]);
    }
    output.push_back((uint8_t)f.ret);
    output.push_back(f.arg.size());

    for (int n = 0; n < f.arg.size(); n++) { 
        output.push_back((uint8_t)std::get<1>(f.arg[n]));
        auto& name = std::get<0>(f.arg[n]);

        output.push_back(name.size()); // func name
        for (int i = 0; i < name.size(); i++) { 
            output.push_back(name[i]);
        }
    }

    auto s = (int32_t)f.data.size();
    for (int i = 0; i < 4; i++) { 
        auto d = ((uint8_t*)&s)[i];
        output.push_back(d);
    }

    for (int i = 0; i < s; i++) { 
        output.push_back(f.data[i]);
    }

    return output;
}

std::vector<uint8_t> codegen::linker::create_linker_to_memory() const { 
    std::vector<uint8_t> output;
    
    for (const auto& p : var) { 
        auto r = convert_var_to_bin(p);
        output.insert(output.end(), r.begin(), r.end());
    }
    
    for (const auto& p : func) { 
        auto r = convert_func_to_bin(p);
        output.insert(output.end(), r.begin(), r.end());
    }

    return output;
}

void codegen::linker::restore_from_memory(const std::vector<uint8_t>& data) { 

}


void codegen::linker::add_var(std::string name, 
                                codegen::variant_type type, 
                                const void* const pos, 
                                int size) { 
    std::vector<uint8_t> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = ((uint8_t*)pos)[i];
    }
    
    var.push_back(variant { 
        .data = data,
        .name = name,
        .type = type,
    });
}

void codegen::linker::add_function(std::string name, 
                        codegen::variant_type ret, 
                        std::vector<std::tuple<std::string, codegen::variant_type>> arg,
                        std::vector<uint8_t> ops) { 
    func.push_back(function { 
        .name = name,
        .ret = ret,
        .arg = arg,
        .data = ops,
    });
}