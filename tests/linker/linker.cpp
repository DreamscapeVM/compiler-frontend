#include <gtest/gtest.h>
#include <linker/linker.h>

#define ADD_TEST_CONVERT_TYPE(ENUM, TYPE) \
TEST(Linker, convert_type_##ENUM) { \
    EXPECT_EQ(linker::convert_type<TYPE>::value, linker::variant_type::ENUM); \
} 

ADD_TEST_CONVERT_TYPE(int8,  int8_t)
ADD_TEST_CONVERT_TYPE(int16, int16_t)
ADD_TEST_CONVERT_TYPE(int32, int32_t)
ADD_TEST_CONVERT_TYPE(int64, int64_t)

ADD_TEST_CONVERT_TYPE(uint8,  uint8_t)
ADD_TEST_CONVERT_TYPE(uint16, uint16_t)
ADD_TEST_CONVERT_TYPE(uint32, uint32_t)
ADD_TEST_CONVERT_TYPE(uint64, uint64_t)

ADD_TEST_CONVERT_TYPE(float32, float)
ADD_TEST_CONVERT_TYPE(float64, double)

ADD_TEST_CONVERT_TYPE(array_uint8,  std::vector<uint8_t>);
ADD_TEST_CONVERT_TYPE(array_uint16, std::vector<uint16_t>);
ADD_TEST_CONVERT_TYPE(array_uint32, std::vector<uint32_t>);
ADD_TEST_CONVERT_TYPE(array_uint64, std::vector<uint64_t>);

ADD_TEST_CONVERT_TYPE(array_int8,   std::vector<int8_t>);
ADD_TEST_CONVERT_TYPE(array_int16,  std::vector<int16_t>);
ADD_TEST_CONVERT_TYPE(array_int32,  std::vector<int32_t>);
ADD_TEST_CONVERT_TYPE(array_int64,  std::vector<int64_t>);

ADD_TEST_CONVERT_TYPE(array_float32,  std::vector<float>);
ADD_TEST_CONVERT_TYPE(array_float64,  std::vector<double>);
ADD_TEST_CONVERT_TYPE(string,  std::string);
