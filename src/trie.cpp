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

// may need normalization later on
// currently assuming all lowercase chars.
void trie::insert(const std::string& word) {
    //if(search(word)) return; // word already exists
    trie_node* temp = root;
    int i = 0; 
    char c = word[i++];

    // should get us to a point where we must insert.
    while(i < word.length() && temp->children[c - 'a'] !=nullptr) {
        temp = temp->children[c - 'a'];
        c = word[i++];
    }

    for(int j = i; j < word.length(); j++) {
        temp->children[c - 'a'] = new trie_node();
        temp = temp->children[c - 'a'];
        temp->data = c;
        c = word[j++];
    }
    temp->terminal = true;
}

void trie::delete_word(const std::string& word) {

}

bool trie::search(const std::string&) {

}

bool trie::prefix_search(const std::string& word) {

}
