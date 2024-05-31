#include <iostream>
#include <args/parsing.h>
#include <codegen/codegen.h>

#include <fstream>



int main(int argc, char** argv) {
    // printf("%d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("%s\n", argv[i]);
    // }
    
    // auto arg = args::parse_argument(argc, argv);
    
    codegen::linker linker;
    linker.add_var("hello world1", 10);
    linker.add_var("hello world2", 10.0);
    linker.add_var("hello world3", 10.0f);
    linker.add_var("hello world4", std::string("hello"));
    linker.add_var("hello world5", std::vector<int> { 1, 2, 3, 4, 5});
    auto m = linker.create_linker_to_memory();
    // for (int i = 0; i < m.size(); i++) { 
    //     printf("%d, ", m[i]);
    // }
    linker.restore_from_memory(m);
    
    return 0;
}