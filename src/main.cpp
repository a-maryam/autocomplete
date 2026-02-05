// main.cpp
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include "../include/trie.h"
#include "../include/reader.h"

int main(int argc, char* argv[]) {
    // change for further args, have to configure api for that eventuality too

    std::vector<std::string> tokens = read_file("./input_files/google-10000-english.txt");
    trie* t = new trie();
    
    for(std::string s : tokens) {
        t->insert(s);
    }

    std::vector<std::string> list = t->words_with_prefix("he");
    for(std::string s : list) {
        std::cout << s + "\n";
    }
    std::cout << "is 'information' in the tree " << t->search("information") << "\n";
    //t->print_trie();
    t->destroy_trie();
    
    delete(t);
    
    return 0;
}

