# FileProcessor# File Processor Application

This application processes a file in three modes:
1. **Count words**: Counts occurrences of a specific word in the file.
2. **Checksum**: Calculates a 32-bit checksum of the file's content, ignoring punctuation.
3. **Help**: Displays help information.

## Build Instructions

### Prerequisites
- CMake 3.10 or higher
- C++11 compatible compiler
- GoogleTest (automatically downloaded and built if not available)

### Steps

1. **Clone the repository**

    ```bash
    git clone <repository_url>
    cd MyProject
    ```

2. **Create a build directory**

    ```bash
    mkdir build
    cd build
    ```

3. **Run CMake to generate build files**

    ```bash
    cmake ..
    ```

4. **Build the project**

    ```bash
    make
    ```

## Run the Application

1. **Create a test file**

    Create a file named `test.tst` with the following content(example):

    ```
    father mother brother sister child mother mother, mother. 
    Mother: mother, mother.
    ```

2. **Run the application**

    ```bash
    ./MyApplication -f test_file.txt -m words -v mother
    ```

    This will output:

    ```
    The word 'mother' appears 6 times in the file.
    ```

    To calculate the checksum:

    ```bash
    ./MyApplication -f test_file.txt -m checksum
    ```

    To display help information:

    ```bash
    ./MyApplication -h
    ```

## Run the Tests

1. **Execute the tests**

    ```bash
    ./runTests
    ```

    This will run the unit tests and display the results.
