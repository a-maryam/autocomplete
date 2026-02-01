// trie.cpp
#include "../include/trie.h"
#include <iostream>

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
    unsigned int i = 0; 

    // should get us to a point where we must insert.
    while(i < word.length() && temp->children[word[i] - 'a'] !=nullptr) {
        temp = temp->children[word[i] - 'a'];
        i++;
    }

    char insert;

    for(unsigned int j = i; j < word.length(); j++) {
        insert = word[j];
        temp->children[insert - 'a'] = new trie_node();
        temp = temp->children[insert - 'a'];
        temp->data = insert;
    }
    temp->terminal = true;
}

// probably don't run on huge input files due to the depth of the call stack. 
void trie::print_trie(trie_node* curr) {
    if(!curr) curr = root;
    for(int i = 0; i < 26; i++) {
        if(curr->children[i] != nullptr) {
            std::cout << curr->children[i]->data;
            print_trie(curr->children[i]);
        }
    }
}

void trie::delete_word(const std::string& word) {
    return;
}

bool trie::search(const std::string&) {
    return false;
}

bool trie::prefix_search(const std::string& word) {
    return false;
}

void trie::destroy_trie(trie_node* curr) {
    if(!curr) curr = root; // probably redo conditions for consistency
    for(int i = 0 ; i < 26; i++) {
        if(curr->children[i]!=nullptr) {
            destroy_trie(curr->children[i]);
        }
    }
    delete(curr);
}
