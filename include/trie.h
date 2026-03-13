#pragma once 
#include <string>
#include <vector>

class trie_node {
    static const int ALPHABET_SIZE = 26;
public:
    char data;
    trie_node* children[ALPHABET_SIZE]; // going to insert a lot of words so array is best
    bool terminal;
    int frequency = 0; // for ranking

    trie_node();
}; 
// frequency ranking (freq should only be for words so should it would just remain zero for nonterminals)
// hashmap with frequency: extra space but clarity 

class trie {
    trie_node* root;
public:
    trie(); // param names optional -- compiler doesn't care
    void insert(const std::string&); // const means no editing string + & means no copying over string
    void delete_word(const std::string&);
    bool search(const std::string&);
    std::vector<std::pair<trie_node*, std::string>> words_with_prefix(const std::string&);
    void print_trie(trie_node* curr = nullptr);
    void destroy_trie(trie_node* curr = nullptr);
    std::vector<std::pair<trie_node*, std::string>> find_all_words(trie_node* root, std::vector<std::pair<trie_node*, std::string>>& words, const std::string& prefix);
    bool node_has_children(trie_node* t);
    void increment_frequency(const std::string& word);
    trie_node* find(const std::string& word);
    std::vector<std::string> top_prefixes_by_rank(const std::string&);

private:
    trie_node* delete_word(trie_node* t, const std::string&, unsigned int); 
};