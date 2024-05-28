#include <iostream>
#include <args/parsing.h>

int main(int argc, char** argv) {
    printf("%d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    
    auto arg = args::parse_argument(argc, argv);
    
    // std::cout << "hello world!\n";
    return 0;
}