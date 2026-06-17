// bridge.cpp
// Pinvoke method
#include "../include/trie.h";

extern "C" {
    __declspec(dllexport) void* create_trie() {
        return new trie();
    }
    __declspec(dllexport) bool 
}