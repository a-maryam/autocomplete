# Personal Notes
## Notes for future me 
- don't have trailing spaces in makefiles 
- using namespace is bad practice 

## TODOs
TODO: 
- prefixes are being incremented and served -- which we do not want.  now I'm going to have to choose functionality. Originally it's supposed to be autocomplete, so the idea would be to suggest words more than suggesting prefixes (actually that should be out of scope because that's a different thing). So, should only increment terminal ranking. Double check terminal markings in trie
=> Add word after user enters/whitespace. What about multiple words? should add to trie after every space. Real services keep suggesting past the first word. My trie only stores characters. So anything supporting multi-word suggestions would have to happen somewhere else (like a db). Auxiliary data structure?
- Also, maybe I should try to see if there's a way we can check if something is a real word. Technically, someone could spam gibberish and the whole trie would be messed up if we had persistence (which I think I'm going to add). I don't think real search cares if something is a real word, if everyone is searching gibberish it will be in the rankings.
- Memory safety/concurrency?
- Track search latency / different input lexicons. 
- Think about multiple word situations 
- Project:
Native C++ Trie => C++/CLI Wrapper => .NET backend API => React Frontend


