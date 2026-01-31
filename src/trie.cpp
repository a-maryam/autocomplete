// trie.cpp
// is it better to use char[] or vector for the children?
// do I want to save memory or have fast access
// with my computer fan whirring louder than niagara falls, I should probably try to reduce memory
// caching will also reduce runtime
#include <vector>

class trie_node {
public:
    char data; // going to have this for debugging but not necessary
    std::vector<trie_node*> children;
    bool terminal;

    trie_node(): terminal(false) {
        children.assign(26, nullptr);
    }
};

class trie {
    trie_node* root; // root holds no data
public:
    trie() {
        root = new trie_node();
    }
};

