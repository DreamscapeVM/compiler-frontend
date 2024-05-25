#ifndef __INCLUDE__ARGS_STRUCTURE_H
#define __INCLUDE__ARGS_STRUCTURE_H

#include <cstdint>
#include <string>
#include <vector>

namespace args {
    struct arguments { 
        bool option_verbose;
        bool option_compile;
        bool option_link;
        
        uint64_t max_register_size;
        
        std::vector<std::string> input;

        std::string output_filename;
        std::string output_directory;
    };
    
    const args::arguments parse_argument(int argc, char** argv);
}

#endif
