#include "file_processor.h"
#include <gtest/gtest.h>
#include <fstream>

class FileProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ofstream outFile(testFile);
        outFile << "mother, father- mother mother child.\n";
        outFile.close();
    }

    void TearDown() override {
        std::remove(testFile.c_str());
    }

    const std::string testFile = "test_file.txt";
};

TEST_F(FileProcessorTest, CountWords) {
    FileProcessor processor(testFile);
    EXPECT_EQ(processor.countWords("mother"), 3);
    EXPECT_EQ(processor.countWords("father"), 1);
    EXPECT_EQ(processor.countWords("child"), 1);
    EXPECT_EQ(processor.countWords("unknown"), 0);
}

TEST_F(FileProcessorTest, CalculateChecksum) {
    std::ofstream outFile("binary_file.bin", std::ios::binary);
    uint32_t words[] = {1, 2, 3, 4};
    outFile.write(reinterpret_cast<char*>(words), sizeof(words));
    outFile.close();

    FileProcessor processor("binary_file.bin");
    EXPECT_EQ(processor.calculateChecksum(), 10); // 1 + 2 + 3 + 4

    std::remove("binary_file.bin");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
