#include <gtest/gtest.h>
#include <vector>
#include <tokenizer/tokenizer.h>

TEST(Tokenizer, check_comment_token1) { 
    tokenizer t;
    auto p = t.read_from_text("# hello world!!!");
    t.set_data(p);
    auto data = t.get_token();
    EXPECT_EQ(std::get<0>(data), token::comment);
    EXPECT_EQ(std::get<1>(data), std::string("# hello world!!!"));
}

TEST(Tokenizer, check_comment_token2) { 
    tokenizer t;
    auto p = t.read_from_text("# hello world!!! ### ");
    t.set_data(p);
    auto data = t.get_token();
    EXPECT_EQ(std::get<0>(data), token::comment);
    EXPECT_EQ(std::get<1>(data), std::string("# hello world!!! ### "));
}

TEST(Tokenizer, check_comment_token3) { 
    tokenizer t;
    auto p = t.read_from_text("# hello world!!! ###\n# asdf ");
    t.set_data(p);
    auto data = t.get_token();
    auto data2 = t.get_token();

    EXPECT_EQ(std::get<0>(data), token::comment);
    EXPECT_EQ(std::get<1>(data), std::string("# hello world!!! ###"));
    EXPECT_EQ(std::get<0>(data2), token::comment);
    EXPECT_EQ(std::get<1>(data2), std::string("# asdf "));
}
