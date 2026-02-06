cmake_minimum_required(VERSION 3.14)
project(autocomplete)
# Prevent GoogleTest from overriding compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
set(LOGIC_SOURCES src/trie.cpp src/reader.cpp)
add_executable(autocomplete src/main.cpp ${LOGIC_SOURCES})

# TEST STUFF
add_subdirectory(googletest)
add_executable(run_tests tests/tests.cpp ${LOGIC_SOURCES})
target_link_libraries(run_tests GTest::gtest_main)

# enable ctest command
enable_testing()
add_test(NAME autocomplete COMMAND run_tests)