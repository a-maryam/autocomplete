import './App.css'
import { useEffect } from "react"
import { getSuggestions } from './services/api'
import Autocomplete from "./components/Autocomplete"

function App() {
  useEffect(() =>{
    getSuggestions("cat")
    .then(data => console.log(data))
    .catch(err => console.error(err))
  }, [])
  return <div>
    <h1> Autocomplete </h1>
     <Autocomplete />
  </div>
}

export default App
