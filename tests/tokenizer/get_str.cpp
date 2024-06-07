#include <gtest/gtest.h>
#include <vector>
#include <tokenizer/tokenizer.h>

#define CHECKS(TOKENIZER, VALUE)         \
{                                       \
    auto data = TOKENIZER.get_str();    \
    EXPECT_EQ(data, VALUE);             \
}

TEST(Tokenizer, check_get_str_token1) { 
    tokenizer t;
    auto p = t.read_from_text("[adsf]");
    t.set_data(p);
    auto data = t.get_str();
    auto data2 = t.get_str();
    auto data3 = t.get_str();

    EXPECT_EQ(data, "[");
    EXPECT_EQ(data2, "adsf");
    EXPECT_EQ(data3, "]");
}

TEST(Tokenizer, check_get_str_token2) { 
    tokenizer t;
    auto p = t.read_from_text("[()}a\"asdasf\")");
    t.set_data(p);
    
    CHECKS(t, "[");
    CHECKS(t, "(");
    CHECKS(t, ")");
    CHECKS(t, "}");
    CHECKS(t, "a");
    CHECKS(t, "\"asdasf\"");
    CHECKS(t, ")");
}

TEST(Tokenizer, check_get_str_token3) { 
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

CHECKS(t, ";"); CHECKS(t, "main"); CHECKS(t, "("); CHECKS(t, "argv"); CHECKS(t, ":"); CHECKS(t, "["); CHECKS(t, "str"); CHECKS(t, "]"); CHECKS(t, ")");
CHECKS(t, "{"); CHECKS(t, "print"); CHECKS(t, "("); CHECKS(t, "str"); CHECKS(t, ")"); CHECKS(t, "mut");
CHECKS(t, "data");
CHECKS(t, ":");
CHECKS(t, "int64");
CHECKS(t, "=");
CHECKS(t, "0");
CHECKS(t, "for");
CHECKS(t, "mut");
CHECKS(t, "i");
CHECKS(t, ":");
CHECKS(t, "int32");
CHECKS(t, "=");
CHECKS(t, "0");
CHECKS(t, ";");
CHECKS(t, "i");
CHECKS(t, "<");
CHECKS(t, "10");
CHECKS(t, ";");
CHECKS(t, "i");
CHECKS(t, "+");
CHECKS(t, "=");
CHECKS(t, "1");
CHECKS(t, "{");
CHECKS(t, "data");
CHECKS(t, "=");
CHECKS(t, "add");
CHECKS(t, "(");
CHECKS(t, "[");
CHECKS(t, "data");
CHECKS(t, ",");
CHECKS(t, "i");
CHECKS(t, ",");
CHECKS(t, "value");
CHECKS(t, "]");
CHECKS(t, ")");
CHECKS(t, "print");
CHECKS(t, "(");
CHECKS(t, "[");
CHECKS(t, "data");
CHECKS(t, ",");
CHECKS(t, "\n");
CHECKS(t, "]");
CHECKS(t, ")");
CHECKS(t, "}");
CHECKS(t, "}");
}

