#ifndef __INCLUDE_TOKENIZER_TOKENIZER_H
#define __INCLUDE_TOKENIZER_TOKENIZER_H

#include <vector>
#include <fstream>
#include <tokenizer/tokenizer.h>

class tokenizer { 
private:

public:
    std::vector<uint8_t> read_from_file(const std::string& filename) const;
    
};

#endif // __INCLUDE_TOKENIZER_TOKENIZER_H

