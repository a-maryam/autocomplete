#include "AutocompleteWrapper.h"


using namespace msclr::interop;

AutocompleteWrapper::AutocompleteWrapper() {
    nativeTrie = new trie();
}

AutocompleteWrapper::~AutocompleteWrapper() {
    this->!AutocompleteWrapper();
}

AutocompleteWrapper::!AutocompleteWrapper() {
    if (nativeTrie != nullptr) {
        delete nativeTrie;
        nativeTrie = nullptr;
    }
}

std::string AutocompleteWrapper::SystemStringToStdString(String^ str) {
    marshal_context context;
    return context.marshal_as<std::string>(str);
}

String^ AutocompleteWrapper::StdStringToSystemString(const std::string& str) {
    return gcnew String(str.c_str());
}

void AutocompleteWrapper::InsertWord(String^ word) {
    nativeTrie->insert_word(SystemStringToStdString(word));
}

bool AutocompleteWrapper::Search(String^ word) {
    return nativeTrie->search(SystemStringToStdString(word));
}

void AutocompleteWrapper::SelectWord(String^ word) {
    nativeTrie->increment_frequency(SystemStringToStdString(word));
}

array<String^>^ AutocompleteWrapper::TopWords(String^ prefix) {
    std::string nativePrefix = SystemStringToStdString(prefix);
    auto words = nativeTrie->top_words_with_prefix(nativePrefix);

    array<String^>^ result = gcnew array<String^>(words.size());
    for (size_t i = 0; i < words.size(); i++) {
        result[i] = gcnew String(words[i].c_str());
    }
    return result;
}