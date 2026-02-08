// tests.cpp
#include <iostream>
#include "gtest/gtest.h"
#include "../include/trie.h" // Replace with your actual project header
#include "../include/reader.h"
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

// UNIT TESTS
// TRIE FUNCTIONS
TEST(trie, insert_and_search) {
    trie* t = new trie();
    t->insert("cat");

    ASSERT_TRUE(t->search("cat"));
    ASSERT_FALSE(t->search("ca"));
    ASSERT_FALSE(t->search("car"));
}

// DELETION
TEST(trie, insert_and_delete_one_word) {
    trie* t = new trie();
    t->insert("cat");

    ASSERT_TRUE(t->search("cat"));

    t->delete_word("cat");

    ASSERT_FALSE(t->search("cat"));
}

TEST(trie, insert_and_delete_related_words) {
    trie* t = new trie();
    t->insert("cat");
    t->insert("catastrophe");
    t->insert("catatonic");
    t->insert("catch");
    t->insert("catharsis");
    t->insert("cacophony");

    ASSERT_TRUE(t->search("catch"));

    t->delete_word("catch");

    ASSERT_FALSE(t->search("catch"));
    //ASSERT_TRUE(t->contains_prefix("cat")) --write this function + this would be an integration test then
}

TEST(trie, delete_in_empty_trie) {
    trie* t = new trie();
    t->delete_word("trie"); // test passes if program does not crash
}

// SEARCH
TEST(trie, search_for_word_not_in_trie) {
    trie* t = new trie();
    t->insert("hello");
    ASSERT_FALSE(t->search("hi"));
}

// INTEGRATION TESTS
// TRIE FUNCTION
TEST(trie, insert_and_search_many_words) {
    trie* t = new trie();
    t->insert("the");
    t->insert("quick");
    t->insert("brown");
    t->insert("fox");

    ASSERT_TRUE(t->search("quick")); 
}

TEST(trie, words_with_prefix_basic) {
    trie* t = new trie();
    t->insert("cat");
    t->insert("catastrophe");
    t->insert("catatonic");
    t->insert("catch");
    t->insert("catharsis");
    t->insert("cacophony");

    std::vector<std::string> words = t->words_with_prefix("cat");
    // checking if words with a prefix are in the list
    ASSERT_TRUE(std::find(words.begin(), words.end(), "catch") != words.end());
    ASSERT_TRUE(std::find(words.begin(), words.end(), "catharsis") != words.end());
}