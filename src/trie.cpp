// trie.cpp
#include "../include/trie.h"
#include <iostream>
#include <vector>
#include <stack>

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
    if(search(word)) return; // word already exists
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

// deep call stack possible
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
    delete_word(root, word, 0);
}

trie_node* trie::delete_word(trie_node* t, const std::string& word, unsigned int depth) {
    // if node has children do not delete
    // unset terminal 
    // delete nodes from the bottom up if there are no children
    if(t == nullptr) return NULL; 
    if(depth == word.length()) {
        if(t->terminal) t->terminal = false;
        if(node_has_children(t)==false) {
            delete(t);
            return nullptr;
        }
    }

    int i =  word[depth] - 'a';
    t->children[i] = delete_word(t->children[i], word, depth + 1);

    if(node_has_children(t)==false && t->terminal == false) {
        delete(t);
        return nullptr;
    }

    return t;
}

bool trie::node_has_children(trie_node* t) {
    for(int i = 0; i < 26; i++) {
        if(t->children[i]!=nullptr) return true;
    }
    return false;
}

bool trie::search(const std::string& target) {
    trie_node* curr = root;
    
    for(unsigned int i = 0; i < target.length(); i++) {
        char c = target[i];
        if(curr->children[c - 'a'] == nullptr) return false;
        curr = curr->children[c - 'a'];
    }

    return curr->terminal;
}

std::vector<std::string> trie::words_with_prefix(const std::string& prefix) {
    std::vector<std::string> words = {};
    trie_node* curr = root; 
    // we get down to the prefix and then we follow every path in the children, 
    // add whatever is terminal...until there are no more branches.
    for(unsigned int i = 0; i < prefix.length(); i++) {
        char c = prefix[i];
        if(curr->children[c - 'a'] == nullptr) return words;
        curr = curr->children[c - 'a'];
    }
    return find_all_words(curr, words, prefix);
}

// dfs
std::vector<std::string> trie::find_all_words(trie_node* root, std::vector<std::string>& words, const std::string& prefix) {
    std::stack<std::pair<trie_node*, std::string>> nodes; 
    nodes.push({root, ""});
    std::string temp;
    std::pair<trie_node*, std::string> p; // have to store path to each node because otherwise it would get lost
    
    while(nodes.empty() == false) {
        auto [curr, temp] = nodes.top();
        nodes.pop();
        if(curr->terminal) {
            words.push_back(prefix + temp); // original mistake was resetting temp here but it is the path
        }
        for(int i = 0; i < 26; i++) {
            if(curr->children[i]!=nullptr) {
                char next_char = 'a' + i;
                nodes.push({curr->children[i], temp + next_char});
            }
        }
    }

    return words;
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
