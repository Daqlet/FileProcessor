#include "file_processor.h"

#include <iostream>
#include <unordered_map>
#include <string>
#include <iomanip>

void printHelp() {
    std::cout << "Usage:\n";
    std::cout << "test -f <filename> -m <mode> [-v <value>]\n";
    std::cout << "Modes:\n";
    std::cout << "  words -v <word> : Count occurrences of <word> in <filename>\n";
    std::cout << "  checksum        : Calculate 32-bit checksum of <filename>\n";
    std::cout << "  -h              : Display this help message\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printHelp();
        return 1;
    }

    std::unordered_map<std::string, std::string> args;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg[0] == '-') {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                args[arg] = argv[i + 1];
                ++i;
            } else {
                args[arg] = "";
            }
        }
    }

    if (args.count("-h") || args.count("--help")) {
        printHelp();
        return 0;
    }

    if (!args.count("-f") || !args.count("-m")) {
        printHelp();
        return 1;
    }

    std::string filename = args["-f"];
    std::string mode = args["-m"];

    try {
        FileProcessor processor(filename);

        if (mode == "words") {
            if (!args.count("-v")) {
                printHelp();
                return 1;
            }
            std::string word = args["-v"];
            int count = processor.countWords(word);
            std::cout << "The word '" << word << "' appears " << count << " times in the file.\n";
        } else if (mode == "checksum") {
            uint32_t checksum = processor.calculateChecksum();
            std::cout << "Checksum: " << std::hex << std::setw(8) << std::setfill('0') << checksum << "\n";
        } else {
            printHelp();
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
