#include <iostream>
#include "gtest/gtest.h"
#include "../include/trie.h" // Replace with your actual project header
#include "../include/reader.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>

TEST(trie, basic_search) {
    trie* t = new trie();
    std::vector<std::string> tokens = read_file("./input_files/small_test.txt");
    for(std::string s : tokens) {
        t->insert(s);
    }
    ASSERT_TRUE(t->search("quick"));
}