#include <tokenizer/tokenizer.h>

std::vector<uint8_t> tokenizer::read_from_file(const std::string& filename) const {
    // Open the file in binary mode
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    // Get the file size
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Resize the vector to hold the file data
    std::vector<uint8_t> buffer(fileSize);

    // Read the file data into the vector
    if (!file.read(reinterpret_cast<char*>(buffer.data()), fileSize)) {
        throw std::runtime_error("Error reading file");
    }

    return buffer;
}

