
#include "../include/reader.h"

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
    
    return tokens; 
}