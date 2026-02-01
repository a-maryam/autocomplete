// main.cpp
#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include "../include/trie.h"

// file input 
// TSV for now 
std::vector<std::string> read_file(std::string fname) {
    std::string word;
    std::ifstream input_file(fname);
    std::vector<std::string> tokens;

    if(input_file.is_open()) {
        while(input_file >> word) { // stream extraction operator
            tokens.push_back(word);
        }
        input_file.close();
    } 
    else {
        std::cout << "Couldn't open file" << std::endl;
    }
    /*for(std::string s : tokens) {
        std::cout << s << '\n';
    }*/
    return tokens; 
}

int main(int argc, char* argv[]) {
    // change for further args
    // don't know what that looks like with an API, but we shall see

    std::vector<std::string> tokens = read_file("./input_files/small_test.txt");
    trie* t = new trie();
    
    for(std::string s : tokens) {
        t->insert(s);
    }

    t->print_trie();
    t->destroy_trie();
    delete(t);
    
    return 0;
}

