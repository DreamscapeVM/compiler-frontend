#include <gtest/gtest.h>
#include <vector>
#include <codegen/codegen.h>

TEST(Linker, linker_gen_with_var) { 
    auto r = std::vector<uint8_t> { 0, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 49, 4, 0, 0, 0, 10, 0, 0, 0, 0, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 50, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 64, 0, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 51, 4, 0, 0, 0, 0, 0, 32, 65, 0, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 52, 6, 0, 0, 0, 104, 101, 108, 108, 111, 0, 0, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 53, 20, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0};
    
    codegen::linker linker;
    linker.add_var("hello world1", 10);
    linker.add_var("hello world2", 10.0);
    linker.add_var("hello world3", 10.0f);
    linker.add_var("hello world4", std::string("hello"));
    linker.add_var("hello world5", std::vector<int> { 1, 2, 3, 4, 5});
    auto m = linker.create_linker_to_memory();
    
    EXPECT_EQ(r, m);    
}
