#include <iostream>
#include <args/parsing.h>
#include <codegen/codegen.h>

int main(int argc, char** argv) {
    // printf("%d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("%s\n", argv[i]);
    // }
    
    auto arg = args::parse_argument(argc, argv);
    
    printf("%d\n", codegen::convert_type<int8_t>::value);
    printf("%d\n", codegen::convert_type<float>::value);
    printf("%d\n", codegen::convert_type<int32_t>::value);

    // std::cout << "hello world!\n";
    return 0;
}