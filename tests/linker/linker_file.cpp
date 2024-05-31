#include <gtest/gtest.h>
#include <vector>
#include <codegen/codegen.h>

TEST(Linker, linker_gen_with_var) { 
    auto r = std::vector<uint8_t> { 0, 7, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 49, 4, 0, 0, 0, 10, 0, 0, 0, 0, 12, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 50, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 64, 0, 11, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 51, 4, 0, 0, 0, 0, 0, 32, 65, 0, 25, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 52, 6, 0, 0, 0, 104, 101, 108, 108, 111, 0, 0, 19, 12, 104, 101, 108, 108, 111, 32, 119, 111, 114, 108, 100, 53, 20, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0 };
    
    codegen::linker linker;
    linker.add_var("hello world1", 10);
    linker.add_var("hello world2", 10.0);
    linker.add_var("hello world3", 10.0f);
    linker.add_var("hello world4", std::string("hello"));
    linker.add_var("hello world5", std::vector<int> { 1, 2, 3, 4, 5});
    auto m = linker.create_linker_to_memory();
    
    EXPECT_EQ(r, m);    
}


TEST(Linker, linker_gen_with_var_restore) { 
    codegen::linker linker;
    linker.add_var("hello world1", 10);
    linker.add_var("hello world2", 10.0);
    linker.add_var("hello world3", 10.0f);
    linker.add_var("hello world4", std::string("hello"));
    linker.add_var("hello world5", std::vector<int> { 1, 2, 3, 4, 5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    auto m = linker.create_linker_to_memory();
    
    codegen::linker linker2;
    linker2.restore_from_memory(m);
    auto o = linker.get_variant();
    auto r = linker2.get_variant();

    EXPECT_EQ(o->size(), r->size());

    for (int i = 0; i < o->size(); i++) {
        EXPECT_EQ(o->at(i).type, r->at(i).type);
        EXPECT_EQ(o->at(i).data, r->at(i).data);
        EXPECT_EQ(o->at(i).name, r->at(i).name);
    }
}
