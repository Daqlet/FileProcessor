include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(runTests test_file_processor.cpp ../src/file_processor.cpp)

target_link_libraries(runTests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)
