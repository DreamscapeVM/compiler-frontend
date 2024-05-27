#include <iostream>
#include <cxxopts.hpp>
#include <args/parsing.h>

const args::arguments args::parse_argument(int argc, char** argv) { 
    cxxopts::Options options("MyProgram", "One line description of MyProgram");

    options.add_options()
        ("v,option_verbose", "bool", cxxopts::value<uint64_t>()->default_value(std::to_string(false)))
        ("c,option_compile", "bool", cxxopts::value<uint64_t>()->default_value(std::to_string(true)))
        ("l,option_link", "bool", cxxopts::value<uint64_t>()->default_value(std::to_string(false)))
        ("r,max_register_size", "int", cxxopts::value<int>()->default_value(std::to_string(8)))
        ("i,code", "string", cxxopts::value<std::vector<std::string>>())
        ("I,compiled_input", "string", cxxopts::value<std::vector<std::string>>())
        ("L,inlcude_directory", "string", cxxopts::value<std::vector<std::string>>())
        ("f,output_filename", "Verbose output", cxxopts::value<bool>()->default_value("main.o"))
        ("f,output_director", "Verbose output", cxxopts::value<bool>()->default_value("."))
        ("h,help", "Print usage")
        ;

    auto result = options.parse(argc, argv);
    if (result.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    auto mem_size = result["max_memory_size"].as<uint64_t>();
    auto reg_size = result["max_register_size"].as<uint64_t>();
    auto ips = result["insturction_per_seconds"].as<uint64_t>();
    auto path_software = result["path_of_software"].as<std::string>();
    auto verbose = result["verbose"].as<bool>();

    return args::arguments { 
        .max_memory_size = mem_size,
        .max_register_size = reg_size,
        .path_of_software = path_software,
        .insturction_per_seconds = ips,
        .verbose = verbose
    };
}