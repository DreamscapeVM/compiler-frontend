#ifndef __INCLUDE_LINKER_TYPE_CONVERT_TYPE_TO_VARIANTTYPE_H
#define __INCLUDE_LINKER_TYPE_CONVERT_TYPE_TO_VARIANTTYPE_H

#include <vector>
#include <string>
#include <linker/type/variant.h>

#define CONVERT_TYPE_MACRO(TYPE, ENUM)          \
template<>                                      \
struct convert_type<TYPE> {                     \
    constexpr static variant_type value = ENUM; \
};

namespace linker {

template<typename T>
struct convert_type { 
    static constexpr variant_type value = variant_type::none;
};

CONVERT_TYPE_MACRO(uint8_t, variant_type::uint8);
CONVERT_TYPE_MACRO(uint16_t, variant_type::uint16);
CONVERT_TYPE_MACRO(uint32_t, variant_type::uint32);
CONVERT_TYPE_MACRO(uint64_t, variant_type::uint64);
CONVERT_TYPE_MACRO(std::vector<uint8_t>, variant_type::array_uint8);
CONVERT_TYPE_MACRO(std::vector<uint16_t>, variant_type::array_uint16);
CONVERT_TYPE_MACRO(std::vector<uint32_t>, variant_type::array_uint32);
CONVERT_TYPE_MACRO(std::vector<uint64_t>, variant_type::array_uint64);


CONVERT_TYPE_MACRO(int8_t, variant_type::int8);
CONVERT_TYPE_MACRO(int16_t, variant_type::int16);
CONVERT_TYPE_MACRO(int32_t, variant_type::int32);
CONVERT_TYPE_MACRO(int64_t, variant_type::int64);
CONVERT_TYPE_MACRO(std::vector<int8_t>, variant_type::array_int8);
CONVERT_TYPE_MACRO(std::vector<int16_t>, variant_type::array_int16);
CONVERT_TYPE_MACRO(std::vector<int32_t>, variant_type::array_int32);
CONVERT_TYPE_MACRO(std::vector<int64_t>, variant_type::array_int64);


CONVERT_TYPE_MACRO(float, variant_type::float32);
CONVERT_TYPE_MACRO(double, variant_type::float64);
CONVERT_TYPE_MACRO(std::vector<float>, variant_type::array_float32);
CONVERT_TYPE_MACRO(std::vector<double>, variant_type::array_float64);

CONVERT_TYPE_MACRO(std::string, variant_type::string);

}

#endif