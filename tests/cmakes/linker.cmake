
add_executable(test_linker tests/linker/linker.cpp 
                            tests/linker/size.cpp
                            tests/linker/linker_file.cpp)

target_link_libraries(test_linker PRIVATE 
            main
            GTest::gtest GTest::gtest_main)

add_test(test_linker test_linker)
