#ifndef __INCLUDE_CODEGEN_TYPE_CONVERT_VARIANTTYPE_TO_SIZE_H
#define __INCLUDE_CODEGEN_TYPE_CONVERT_VARIANTTYPE_TO_SIZE_H


#include <linker/type/variant.h>

#define CONVERT_VARIANTTYPE_MACRO(ENUM, SIZE) \
    case ENUM:   \
        return SIZE;

namespace linker { 
constexpr size_t convert_varianttype(variant_type t) { 
    switch (t) {
        CONVERT_VARIANTTYPE_MACRO(variant_type::int8, 1);
        CONVERT_VARIANTTYPE_MACRO(variant_type::int16, 2);
        CONVERT_VARIANTTYPE_MACRO(variant_type::int32, 4);
        CONVERT_VARIANTTYPE_MACRO(variant_type::int64, 8);

        CONVERT_VARIANTTYPE_MACRO(variant_type::uint8, 1);
        CONVERT_VARIANTTYPE_MACRO(variant_type::uint16, 2);
        CONVERT_VARIANTTYPE_MACRO(variant_type::uint32, 4);
        CONVERT_VARIANTTYPE_MACRO(variant_type::uint64, 8);

        CONVERT_VARIANTTYPE_MACRO(variant_type::float8, 1);
        CONVERT_VARIANTTYPE_MACRO(variant_type::float16, 2);
        CONVERT_VARIANTTYPE_MACRO(variant_type::float32, 4);
        CONVERT_VARIANTTYPE_MACRO(variant_type::float64, 8);

        default:
            return 8; // because, pointer size is 8 byte.

    }
}

}

#endif // __INCLUDE_CODEGEN_TYPE_CONVERT_VARIANTTYPE_TO_SIZE_H