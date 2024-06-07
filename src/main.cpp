#include <iostream>
#include <args/parsing.h>
#include <tokenizer/tokenizer.h>

int main(int argc, char** argv) {
    // // printf("%d\n", argc);
    // // for (int i = 0; i < argc; i++) {
    // //     printf("%s\n", argv[i]);
    // // }
    
    // auto arg = args::parse_argument(argc, argv);
    

    tokenizer t;
    auto p = t.read_from_text("                       \
; main (argv: [str]) {                                \
    print(str)                                        \
    mut data: int64 = 0                               \
    for mut i: int32 = 0; i < 10; i += 1 {            \
        data = add([data, i, value])                  \
        print([data, '\n'])                           \
    }                                                 \
}                                                     \
");
    t.set_data(p);

    while (true) { 
        auto data2 = t.get_str();
        std::cout << "CHECKS(t, \"" << data2 << "\");\n";
    }
    
    return 0;
}
