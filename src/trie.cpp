// trie.cpp
#include "../include/trie.h"

trie_node::trie_node() : data(0), terminal(false) {
    for(int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

trie::trie() {
    root = new trie_node();
}

void trie::insert(const std::string& word) {

}

void trie::delete_word(const std::string& word) {

}

bool trie::prefix_search(const std::string& word) {

}
