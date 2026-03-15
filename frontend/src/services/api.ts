
export async function getSuggestions(query: string) {
    const res = await fetch(`/autocomplete?prefix=${encodeURIComponent(query)}`);
    
    if(!res.ok) {
        throw new Error("Fetching suggestions failed.");
    }
    
    return res.json();
}