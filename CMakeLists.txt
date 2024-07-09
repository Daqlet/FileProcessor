cmake_minimum_required(VERSION 3.10)

project(test_app)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(test_app src/main.cpp src/file_processor.cpp)

enable_testing()
add_subdirectory(tests)
