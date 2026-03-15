# Autocomplete backend 
This project is a React + .NET app that is C++ under the hood. I used C++/CLI to expose the trie data structure which facilitates autocomplete. I did not host it to keep down cloud costs because there are basically no free/low-paid options for .NET backends and can't containerize with Docker (don't have Windows Server). I'm going to add a demo video or images soon though.

## Features
- trie with insert, delete, search, prefix search
- Test suite for trie functions
- Using Google Test / Google C++ Testing Framework for tests 
- Using Cmake for the first time (can still compile with makefile but it's not compatible with gtest at the moment)
- C++/CLI Wrapper bridges C++ and C#
- dotnet web api

## Design considerations
### Frequency ranking
- Have the option of adding frequency to nodes or having a hashmap with word frequencies. Adding to nodes saves memory.
- No caching, because then I lose the word ranking updates.

## Idea
- Search/Autocomplete API
- load in words, ranking, cache, api layer

## How this project grew
- First I thought tries and autocomplete were interesting. And I also like C++, and then I wanted to use C#/.NET. So, I had to use C++/CLI to bridge C++ into .NET. It's a pretty old piece of tech that still works.

## Convention choices
- I like the look of lowercase class names, and I like underscores for naming over pascal case. I have remained consistent across my project.