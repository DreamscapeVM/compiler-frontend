#include <iostream>
#include <args/parsing.h>
#include <codegen/codegen.h>

#include <fstream>

void write_vector_to_file(const std::string& filename, const std::vector<uint8_t>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(data.data()), data.size());
    if (!file) {
        std::cerr << "Failed to write data to file: " << filename << std::endl;
    }

    file.close();
}


int main(int argc, char** argv) {
    // printf("%d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("%s\n", argv[i]);
    // }
    
    auto arg = args::parse_argument(argc, argv);
    
    printf("%hhu\n", codegen::convert_type<int8_t>::value);
    printf("%hhu\n", codegen::convert_type<float>::value);
    printf("%hhu\n", codegen::convert_type<int32_t>::value);

    codegen::linker linker;
    linker.add_var("hello world1", 10);
    linker.add_var("hello world2", 10.0);
    linker.add_var("hello world3", 10.0f);
    linker.add_var("hello world4", std::string("hello"));
    linker.add_var("hello world5", std::vector<int> { 1, 2, 3, 4, 5});

    auto result = linker.create_linker_to_memory();
    write_vector_to_file("linker_test.ln", result);

    // std::cout << "hello world!\n";
    return 0;
}