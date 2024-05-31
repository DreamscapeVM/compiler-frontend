#include <gtest/gtest.h>
#include <codegen/codegen.h>

#define ADD_TEST_CONVERT_TYPE(ENUM, SIZE) \
TEST(Linker, convert_variant_type_##ENUM) { \
    EXPECT_EQ(codegen::convert_varianttype(codegen::variant_type::ENUM), SIZE); \
} 

ADD_TEST_CONVERT_TYPE(int8,  1)
ADD_TEST_CONVERT_TYPE(int16, 2)
ADD_TEST_CONVERT_TYPE(int32, 4)
ADD_TEST_CONVERT_TYPE(int64, 8)

ADD_TEST_CONVERT_TYPE(uint8,  1)
ADD_TEST_CONVERT_TYPE(uint16, 2)
ADD_TEST_CONVERT_TYPE(uint32, 4)
ADD_TEST_CONVERT_TYPE(uint64, 8)

ADD_TEST_CONVERT_TYPE(float32, 4)
ADD_TEST_CONVERT_TYPE(float64, 8)

ADD_TEST_CONVERT_TYPE(array_uint8,  8);
ADD_TEST_CONVERT_TYPE(array_uint16, 8);
ADD_TEST_CONVERT_TYPE(array_uint32, 8);
ADD_TEST_CONVERT_TYPE(array_uint64, 8);

ADD_TEST_CONVERT_TYPE(array_int8,   8);
ADD_TEST_CONVERT_TYPE(array_int16,  8);
ADD_TEST_CONVERT_TYPE(array_int32,  8);
ADD_TEST_CONVERT_TYPE(array_int64,  8);
