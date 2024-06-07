#ifndef __INCLUDE_TOKENIZER_TOKENIZER_H
#define __INCLUDE_TOKENIZER_TOKENIZER_H

#include <vector>
#include <tuple>
#include <cstdint>
#include <spdlog/spdlog.h>

#include <tokenizer/token.h>
#include <tokenizer/tokenizer.h>

class tokenizer { 
public:
    using memory_data = std::vector<uint8_t>;
    const std::vector<std::string> reserved_word {
        "let",
        "mut",
        "if",
        "for",
        "while"
    };

#define ADD_SPECIAL_CHAR(DATA, CHARACTER) \
    case DATA: result += CHARACTER; break;
    

private:
    memory_data data;
    memory_data::const_iterator iter;

public:
    memory_data read_from_text(const std::string& text) const;
    memory_data read_from_file(const std::string& filename) const;

    void set_data(const std::vector<uint8_t>& data) { 
        this->data = data;
        this->iter = this->data.begin();
    }

    template<typename T, std::size_t S>
    bool is_in(const T (&data)[S], const T& target) {
        for (const auto& d : data) { 
            if (d == target) { 
                return true;
            }
        }
        return false;
    }

    std::string get_str();

    std::tuple<token, std::string> get_token() { 
        if (iter == data.end()) { 
            return std::make_tuple(token::eof, "");
        }

        for (; iter != data.end(); ++iter) {
            // this is comments. skip until find a new line.
            if (*iter == '#') { 
                std::string result;

                for (; iter != data.end(); ++iter) {
                    if (*iter == '\n' ||
                        *iter == '\r') {
                        // finish 
                        break;
                    }
                    result += *iter;
                }
                return std::make_tuple(token::comment, result);
            }
            
            if (*iter == ';') {
                // next, important word, if data => static,
                // function => create func
                // main => entry point
                auto name = get_str();
                if (name == "main") { 
                    // entrypoint main!
                    
                }else if (name == "data") { 
                    // section for data and static
                }else if (name == "function") { 
                    // define for function.

                }
            }
        }


        return std::make_tuple(token::error, std::string());
    }
};

#endif // __INCLUDE_TOKENIZER_TOKENIZER_H

