#ifndef __INCLUDE_TOKENIZER_TOKENIZER_H
#define __INCLUDE_TOKENIZER_TOKENIZER_H

#include <vector>
#include <tuple>
#include <cstdint>

#include <tokenizer/token.h>
#include <tokenizer/tokenizer.h>


class tokenizer { 
private:
    std::vector<uint8_t> data;

public:
    std::vector<uint8_t> read_from_file(const std::string& filename) const;

    void set_data(const std::vector<uint8_t>& data) { 
        this->data = data;
    }

    std::tuple<token, std::string> get_token() const { 
        return std::make_tuple(token::data_type, "");
    }
};

#endif // __INCLUDE_TOKENIZER_TOKENIZER_H

