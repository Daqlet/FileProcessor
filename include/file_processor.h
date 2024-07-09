#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>
#include <vector>
#include <cstdint>

class FileProcessor {
public:
    FileProcessor(const std::string& filename);

    int countWords(const std::string& word) const;
    uint64_t calculateChecksum() const;

private:
    std::string filename_;

    std::string removePunctuation(const std::string& str) const;
};

#endif // FILEPROCESSOR_H
