#pragma once 
#include <string>

class trie_node {
    
public:
    char data;
    trie_node* children[26]; // going to insert a lot of words so array is best
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
}