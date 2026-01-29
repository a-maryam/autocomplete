// main.cpp
#include <iostream> 
#include <string>
#include <fstream>

// file input 
// TSV for now 
int read_file(std::string fname) {
    std::string line;
    std::ifstream input_file(fname);

    if(input_file.is_open()) {
        while(std::getline(input_file, line)) {
            std::cout << line << std::endl;
        }
        input_file.close();
    } 
    else {
        std::cout << "Couldn't open file" << std::endl;
    }
    return 0; 
}

int main(int argc, char* argv[]) {
    /*if(argc >=1) {
        std::string f_name(argv[0]);
        readfile(f_name)
    }*/
    read_file("./input_files/google-10000-english.txt");
    
    return 0;
}

