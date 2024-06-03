#ifndef __INCLUDE_TOKENIZER_TOKENIZER_H
#define __INCLUDE_TOKENIZER_TOKENIZER_H

#include <vector>
#include <tuple>
#include <cstdint>

#include <tokenizer/token.h>
#include <tokenizer/tokenizer.h>


class tokenizer { 
private:
    using memory_data = std::vector<uint8_t>;
    memory_data data;
    memory_data::const_iterator iter;

public:
    std::vector<uint8_t> read_from_file(const std::string& filename) const;

    void set_data(const std::vector<uint8_t>& data) { 
        this->data = data;
        this->iter = this->data.begin();
    }

    std::tuple<token, std::string> get_token() { 
        if (iter == data.end()) { 
            return std::make_tuple(token::eof, "");
        }

        std::string result;
        
        while (iter == data.end()) { 
            char cur_data = *iter;
            // this is comments. skip until find a new line.
            if (cur_data == '#') { 
                for (; iter == data.end(); ++iter) { 
                    if (cur_data == ' ' || 
                        cur_data == '\n' ||
                        cur_data == '\r') {
                        // finish 
                        return std::make_tuple(token::comment, result);
                    }
                }
            }

            result += cur_data;
        }


        return std::make_tuple(token::error, result);
    }
};

#endif // __INCLUDE_TOKENIZER_TOKENIZER_H

