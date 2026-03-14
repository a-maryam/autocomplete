# Autocomplete backend 

## In-progress
- Wrote trie with insert, delete, search, prefix search
- Wrote basic test suite for trie functions
- Using Google Test / Google C++ Testing Framework for tests 
- Using Cmake for the first time (can still compile with makefile but have not edited it to be compatible with gtest yet)
- dotnet web api

## Design considerations
### Frequency ranking
- Have the option of adding frequency to nodes or having a hashmap with word frequencies. Adding to nodes saves memory. 

## Idea
- Search/Autocomplete API
- load in words, ranking, cache, api layer

## Convention choices
- I like the look of lowercase class names, and I like underscores for naming over pascal case. I have remained consistent across my project. 

## Notes for future me 
- don't have trailing spaces in makefiles 
- using namespace is bad practice 