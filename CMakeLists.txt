cmake_minimum_required(VERSION 3.14)
project(autocomplete)
# Prevent GoogleTest from overriding compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Point this to the folder you just saw (the one with CMakeLists.txt)
add_subdirectory(googletest)

# Now you can link your test executable
add_executable(my_tests tests/tests.cpp src/trie.cpp src/reader.cpp)
target_link_libraries(my_tests GTest::gtest_main)