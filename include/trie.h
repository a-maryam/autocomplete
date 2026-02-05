#pragma once 
#include <string>
#include <vector>

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
    std::vector<std::string> words_with_prefix(const std::string&);
    void print_trie(trie_node* curr = nullptr);
    void destroy_trie(trie_node* curr = nullptr);
    std::vector<std::string> find_all_words(trie_node* root, std::vector<std::string>& words, const std::string& prefix);
};