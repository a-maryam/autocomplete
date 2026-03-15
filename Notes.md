# Personal Notes
## Notes for future me 
- don't have trailing spaces in makefiles 
- using namespace is bad practice 

## TODOs
TODO: 
- prefixes are being incremented and served -- which we do not want.  now I'm going to have to choose functionality. Originally it's supposed to be autocomplete, so the idea would be to suggest words more than suggesting prefixes (actually that should be out of scope because that's a different thing). So, should only increment terminal ranking. 
- Also, maybe I should try to see if there's a way we can check if something is a real word. Technically, someone could spam gibberish and the whole trie would be messed up if we had persistence (which I think I'm going to add).