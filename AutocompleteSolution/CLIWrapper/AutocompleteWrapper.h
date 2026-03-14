#pragma once
#include "../../include/trie.h"
#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace System::Collections::Generic;

public ref class AutocompleteWrapper {
private:
    trie* nativeTrie;
    //Dictionary<String^, array<String^>^>^ _cache;
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
