#include "AutocompleteWrapper.h"


using namespace msclr::interop;

AutocompleteWrapper::AutocompleteWrapper() {
    nativeTrie = new trie();
    //_cache = gcnew Dictionary<String^, array<String^>^>();
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

// Conversions between managed and native strings
std::string AutocompleteWrapper::SystemStringToStdString(String^ str) {
    marshal_context context;
    return context.marshal_as<std::string>(str); // converts data between native and managed types
}

// String^ is a managed string object / GC handles it
String^ AutocompleteWrapper::StdStringToSystemString(const std::string& str) {
    return gcnew String(str.c_str());
} // end conversion functions

void AutocompleteWrapper::InsertWord(String^ word) {
    nativeTrie->insert_word(SystemStringToStdString(word));
}

bool AutocompleteWrapper::Search(String^ word) {
    return nativeTrie->search(SystemStringToStdString(word));
}

void AutocompleteWrapper::SelectWord(String^ word) {
    nativeTrie->increment_frequency(SystemStringToStdString(word));
}

void AutocompleteWrapper::LoadLexicon(String^ path) {
    std::string nativePath = msclr::interop::marshal_as<std::string>(path);
    nativeTrie->load_lexicon(nativePath);
}

// return .NET Array
array<String^>^ AutocompleteWrapper::TopWords(String^ prefix) {
    // gcnew allocates memory on heap 
    if (String::IsNullOrEmpty(prefix)) return gcnew array<String^>(0);
    prefix = prefix->ToLower(); // normalize

	// return from cache if saved, only top 10 so should not take up too much memory
    //array<String^>^ cached;
    //if (_cache->TryGetValue(prefix, cached)) return cached;

    std::string nativePrefix = SystemStringToStdString(prefix);
    auto words = nativeTrie->top_words_with_prefix(nativePrefix);

    array<String^>^ result = gcnew array<String^>(words.size());
    for (size_t i = 0; i < words.size(); i++) {
        result[i] = gcnew String(words[i].c_str());
    }
	//_cache[prefix] = result; // cache the result
    return result;
}