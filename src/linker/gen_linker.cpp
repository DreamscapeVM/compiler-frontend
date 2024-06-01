#include <sstream>
#include <fstream>

#include <linker/gen_linker.h>

const std::vector<linker::variant>* const linker::gen_linker::get_variant() const { 
    return &var;
}
const std::vector<linker::function>* const linker::gen_linker::get_function() const { 
    return &func;
}

std::vector<uint8_t> linker::gen_linker::convert_var_to_bin(const linker::variant& v) const { 
    std::vector<uint8_t> output;
    output.push_back(0); // var type define
    output.push_back((uint8_t)v.type);

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

std::vector<uint8_t> linker::gen_linker::convert_func_to_bin(const linker::function& f) const { 
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

linker::variant linker::gen_linker::convert_bin_to_var(const std::vector<uint8_t>& v, int& index) const {
    auto type = v[index++];
    auto name_size = v[index++];
    
    std::string n(v.begin() + index, v.begin() + index + name_size);
    index += name_size;

    int s = *(int*)((v.begin() + index).base());
    index += 4;
    std::vector<uint8_t> d(v.begin() + index, v.begin() + (index + s));
    index += s;

    return linker::variant {
        .type = static_cast<linker::variant_type>(type),
        .name = n,
        .data = d,
    };
}

linker::function linker::gen_linker::convert_bin_to_func(const std::vector<uint8_t>& v, int& index) const { 
    auto name_size = v[index++];
    std::string n(v.begin() + index, v.begin() + index + name_size);
    index += name_size;

    auto ret_type = v[index++];
    auto arg_size = v[index++];

    std::vector<std::tuple<std::string, linker::variant_type>> arg;

    for (int n = 0; n < arg_size; n++) { 
        linker::variant_type type = static_cast<linker::variant_type>(v[index++]);
        auto arg_name_size = v[index++];
        std::string arg_name(v.begin() + index, v.begin() + index + arg_name_size);
        index += arg_name_size;
        arg.push_back(std::make_tuple(arg_name, type));
    }


    int32_t data_size = *(int*)((v.begin() + index).base());
    index += 4;
    std::vector<uint8_t> d(v.begin() + index, v.begin() + (index + data_size));
    index += data_size;

    return linker::function{
        .ret = static_cast<linker::variant_type>(ret_type),
        .name = n,
        .arg = arg,
        .data = d
    };
}

std::vector<uint8_t> linker::gen_linker::create_linker_to_memory() const { 
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

void linker::gen_linker::create_linker_to_file(const std::string& filename) const {
    auto data = create_linker_to_memory();
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filename);
        return;
    }

    file.write(reinterpret_cast<const char*>(data.data()), data.size());
    if (!file) {
        throw std::runtime_error("Failed to write data to file: " + filename);
    }

    file.close();
}

void linker::gen_linker::restore_from_memory(const std::vector<uint8_t>& data) { 
    // TODO: restore from memory
    int index = 0;
    this->var.clear();
    this->func.clear();
    
    while (index < data.size()) {
        auto d = data[index];
        index += 1;

        if (d == 0) { // var 
            this->var.push_back(convert_bin_to_var(data, index));
        }else {                 // func
            this->func.push_back(convert_bin_to_func(data, index));
        }
    }
}


void linker::gen_linker::add_var(std::string name, 
                                linker::variant_type type, 
                                const void* const pos, 
                                int size) { 
    std::vector<uint8_t> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = ((uint8_t*)pos)[i];
    }
    
    var.push_back(linker::variant { 
        .type = type,
        .name = name,
        .data = data,
    });
}

void linker::gen_linker::add_function(std::string name, 
                        linker::variant_type ret, 
                        std::vector<std::tuple<std::string, linker::variant_type>> arg,
                        std::vector<uint8_t> ops) { 
    func.push_back(function { 
        .ret = ret,
        .name = name,
        .arg = arg,
        .data = ops,
    });
}