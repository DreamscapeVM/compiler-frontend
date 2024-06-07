
add_executable(test_tokenizer   tests/tokenizer/comments.cpp
                                tests/tokenizer/get_str.cpp)

target_link_libraries(test_tokenizer PRIVATE 
            main
            GTest::gtest GTest::gtest_main)

add_test(test_tokenizer test_tokenizer)
