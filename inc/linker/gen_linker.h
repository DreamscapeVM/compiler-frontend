#ifndef __INCLUDE_LINKER_GEN_H
#define __INCLUDE_LINKER_GEN_H

#include <string>
#include <vector>
#include <tuple>

#include <linker/type/variant.h>
#include <linker/type/function.h>
#include <linker/type/convert_type_to_varianttype.h>
#include <linker/type/convert_varianttype_to_size.h>

namespace linker {
class gen_linker
{
private:
    std::vector<variant> var;
    std::vector<function> func;
    void add_var(std::string name, variant_type type, const void* const pos, int size);

    std::vector<uint8_t> convert_var_to_bin(const variant& v) const;
    std::vector<uint8_t> convert_func_to_bin(const function& f) const;

    variant convert_bin_to_var(const std::vector<uint8_t>& v, int& index) const;
    function convert_bin_to_func(const std::vector<uint8_t>& v, int& index) const;

public:

    const std::vector<variant>* const get_variant() const;
    const std::vector<function>* const get_function() const;
    std::vector<uint8_t> create_linker_to_memory() const;
    void restore_from_memory(const std::vector<uint8_t>& data);

    void create_linker_to_file(const std::string& filename) const;

public:
    void add_function(std::string name, 
                        variant_type ret, 
                        std::vector<std::tuple<std::string, variant_type>> arg,
                        std::vector<uint8_t> ops);

    template<typename T>
    void add_var(std::string name, const T& value) { 
        auto size = sizeof(T); 
        T copy = value;
        add_var(name, convert_type<T>::value, (void*)&copy, size);
    }

    template<typename T>
    void add_var(std::string name, const std::vector<T>& value) { 
        auto size = sizeof(T) * value.size();
        add_var(name, convert_type<std::vector<T>>::value, (void*)value.data(), size);
    }

    template<>
    void add_var(std::string name, const std::string& value) { 
        auto size = value.size() + 1; // size + 1, because of null
        add_var(name, convert_type<std::string>::value, (void*)value.data(), size);
    }
};


}

#endif
