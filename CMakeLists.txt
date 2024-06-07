SET(PROJ_NAME DreamscapeCompiler)
cmake_minimum_required(VERSION 3.22)
project(${PROJ_NAME})

SET(USE_GTEST ON)

set(CMAKE_CXX_STANDARD              17)
set(CMAKE_C_STANDARD_REQUIRED       ON)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_C_EXTENSIONS              OFF)
set(CMAKE_CXX_EXTENSIONS            OFF)

if (USE_GTEST)
    enable_testing()
    find_package(GTest CONFIG REQUIRED)
endif()

find_package(cxxopts CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/lib/virtual-machine/inc)

SET (SRC_PARSER             src/args/parser.cpp)
SET (SRC_LINKER            src/linker/gen_linker.cpp)
SET (SRC_TOKENIZER          src/tokenizer/tokenizer.cpp)

add_library(main  ${SRC_PARSER} ${SRC_LINKER} ${SRC_TOKENIZER})

target_link_libraries(main PUBLIC spdlog::spdlog)
target_link_libraries(main PUBLIC cxxopts::cxxopts)

if (USE_GTEST)
    include(${CMAKE_SOURCE_DIR}/tests/cmakes/linker.cmake)
    include(${CMAKE_SOURCE_DIR}/tests/cmakes/tokenizer.cmake)
endif()

add_executable(${PROJ_NAME} src/main.cpp)


target_link_libraries(${PROJ_NAME} PRIVATE main)
