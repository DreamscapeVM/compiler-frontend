#include <iostream>
#include <cxxopts.hpp>
#include <args/parsing.h>

const args::arguments args::parse_argument(int argc, char** argv) { 
    cxxopts::Options options("MyProgram", "One line description of MyProgram");

    options.add_options()
        ("v,option_verbose", "bool", cxxopts::value<bool>()->default_value(std::to_string(false)))
        ("c,option_compile", "bool", cxxopts::value<bool>()->default_value(std::to_string(true)))
        ("l,option_link", "bool", cxxopts::value<bool>()->default_value(std::to_string(false)))
        ("r,max_register_size", "int", cxxopts::value<uint64_t>()->default_value(std::to_string(8)))
        ("i,code", "[string]", cxxopts::value<std::vector<std::string>>())
        ("I,compiled_input", "[string]", cxxopts::value<std::vector<std::string>>()->default_value(""))
        ("L,inlcude_directory", "[string]", cxxopts::value<std::vector<std::string>>()->default_value("."))
        ("f,output_filename", "[string]", cxxopts::value<std::string>()->default_value("main.o"))
        ("d,output_director", "[string]", cxxopts::value<std::string>()->default_value("."))
        ("h,help", "Print usage")
        ;
    
    try { 
        auto result = options.parse(argc, argv);
        if (result.count("help"))
        {
            std::cout << options.help() << std::endl;
            exit(0);
        }
        return args::arguments { 
            .option_verbose = result["option_verbose"].as<bool>(),
            .option_compile = result["option_compile"].as<bool>(),
            .option_link = result["option_link"].as<bool>(),
            .max_register_size = result["max_register_size"].as<uint64_t>(),
            .code = result["code"].as<std::vector<std::string>>(),
            .compiled_input = result["compiled_input"].as<std::vector<std::string>>(),
            .inlcude_directory = result["inlcude_directory"].as<std::vector<std::string>>(),
            .output_filename = result["output_filename"].as<std::string>(),
            .output_directory = result["output_director"].as<std::string>()
        };
    }catch (cxxopts::exceptions::exception e) { 
        std::cout << e.what() <<  options.help() << std::endl;
        exit(0);
    }
}