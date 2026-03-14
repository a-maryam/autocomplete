#pragma once
#include "../../include/trie.h"
//#include "../TrieLib/include/trie.h"
#include <msclr/marshal_cppstd.h>

using namespace System;

public ref class AutocompleteWrapper {
private:
    trie* nativeTrie;
    std::string SystemStringToStdString(String^ str);
    String^ StdStringToSystemString(const std::string& str);

    public:
        AutocompleteWrapper();
        ~AutocompleteWrapper();
        !AutocompleteWrapper();

        void InsertWord(String^ word);
        bool Search(String^ word);
        void SelectWord(String^ word);
        array<String^>^ TopWords(String^ prefix);
        void LoadLexicon(String^ path);
    };
