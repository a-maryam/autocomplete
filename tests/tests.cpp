// tests.cpp
#include <iostream>
#include "gtest/gtest.h"
#include "../include/trie.h" // Replace with your actual project header
#include "../include/reader.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>

// UNIT TESTS
// TRIE FUNCTIONS
TEST(trie, insert_and_search) {
    trie* t = new trie();
    t->insert("cat");

    ASSERT_TRUE(t->search("cat"));
    ASSERT_FALSE(t->search("ca"));
    ASSERT_FALSE(t->search("car"));
}

// INTEGRATION TEST
// TRIE FUNCTION
TEST(trie, insert_and_search_many_words) {
    trie* t = new trie();
    t->insert("the");
    t->insert("quick");
    t->insert("brown");
    t->insert("fox");

    ASSERT_TRUE(t->search("quick")); 
}