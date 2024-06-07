#include <fstream>
#include <tokenizer/tokenizer.h>


tokenizer::memory_data tokenizer::read_from_text(const std::string& text) const { 
    tokenizer::memory_data vec(text.begin(), text.end());
    return vec;
}

tokenizer::memory_data tokenizer::read_from_file(const std::string& filename) const {
    // Open the file in binary mode
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    // Get the file size
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Resize the vector to hold the file data
    tokenizer::memory_data buffer(fileSize);

    // Read the file data into the vector
    if (!file.read(reinterpret_cast<char*>(buffer.data()), fileSize)) {
        throw std::runtime_error("Error reading file");
    }

    return buffer;
}


  std::string tokenizer::get_str() { 
        // [, ], (, ), ;, :, \n, \r, eof, op, , \', \", ' '
        constexpr char reserved_split_data[] = "{}[]():;,+-*/%=";
        constexpr char timing_of_ensure_split[4] = "\n\r ";
        constexpr char text_start[] = "\'\"";
        constexpr char all[] = "{}[]():;\n\r \'\",+-*/%=";

        std::string result;
        for (; iter != data.end(); ) {
            if (result.empty() && is_in(timing_of_ensure_split, (char)*iter)) { 
                iter++;
            }else { 
                break;
            }
        }

        if (iter == data.end()) {
            return "";
        }

        if (is_in(reserved_split_data, (char)*iter)) { 
            result += *iter;
            iter++;
            return result;
        }

        if (is_in(text_start, (char)*iter)){ 
            result += *iter;
            iter++;

            for (; iter != data.end(); iter++) { 
                constexpr char speical_char[] = "\\";
                if (is_in(speical_char, (char)*iter)) { 
                    iter++;
                    switch (*iter){ 
                        ADD_SPECIAL_CHAR('n', '\n');
                        ADD_SPECIAL_CHAR('r', '\r');
                        ADD_SPECIAL_CHAR('a', '\a');
                        ADD_SPECIAL_CHAR('0', '\0');
                        ADD_SPECIAL_CHAR('\\', '\\');
                        ADD_SPECIAL_CHAR('\'', '\'');
                        ADD_SPECIAL_CHAR('\"', '\"');
                        default:
                            spdlog::info("not defineded in compiler!");
                            break;
                    }
                }

                result += *iter;
                if (is_in(text_start, (char)*iter)){ 
                    iter++;
                    return result;
                }
            }
        }

        for (; !is_in(all, (char)*iter); iter++) { 
            result += *iter;
        }

        return result;
    }

