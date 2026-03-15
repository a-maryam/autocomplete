import { useState } from "react"
import { getSuggestions } from "../services/api"

export default function Autocomplete() {
    // usestate init
    const[query, setQuery] = useState(""); // init empty string
    const [suggestions, setSuggestions] = useState<string[]>([]); 

    // triggered by input
    // this function makes it so that prefixes are sent to the backend as they are typed
    async function handleChange(e: React.ChangeEvent<HTMLInputElement>) {
        const value = e.target.value;
        setQuery(value);
        if(!value) {
            setSuggestions([]);
            return;
        }

        const results = await getSuggestions(value);
        setSuggestions(results);
    }

    return (
        <div>
            <input value={query}
            onChange = {handleChange}
            placeholder="Search..."/>
        <ul>
            {suggestions.map((s,i) => (<li key = {i}>{s} </li>))}
        </ul>
        </div>
    )
}