#pragma once 
#include <string>

class trie_node {
    static const int ALPHABET_SIZE = 26;
public:
    char data;
    trie_node* children[ALPHABET_SIZE]; // going to insert a lot of words so array is best
    bool terminal;

    trie_node();
};

class trie {
    trie_node* root;
public:
    trie(); // param names optional -- compiler doesn't care
    void insert(const std::string&); // const means no editing string + & means no copying over string
    void delete_word(const std::string&);
    bool search(const std::string&);
    bool prefix_search(const std::string&);
    void print_trie(trie_node* curr = nullptr);
    void destroy_trie(trie_node* curr = nullptr);
};