#include "file_processor.h"

#include <fstream>
#include <numeric>
#include <stdexcept>
#include <algorithm>
#include <cctype>

FileProcessor::FileProcessor(const std::string& filename) : filename_(filename) {}

std::string FileProcessor::removePunctuation(const std::string& str) const {
    std::string result;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result), ::ispunct);
    return std::move(result);
}

int FileProcessor::countWords(const std::string& word) const {
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    int count = 0;
    std::string currentWord;
    while (file >> currentWord) {
        if (removePunctuation(currentWord) == word) {
            ++count;
        }
    }
    return count;
}

uint64_t FileProcessor::calculateChecksum() const {
    std::ifstream file(filename_, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::vector<uint64_t> checksums;
    std::string currentWord;
    while (file >> currentWord) {
        currentWord = std::move(removePunctuation(currentWord));
        uint64_t checksum = 0;
        for (char ch: currentWord) {
            checksum += int(ch);
        }
        checksums.emplace_back(checksum);
    }
    return std::accumulate(checksums.begin(), checksums.end(), 0uLL);
}
