using Microsoft.AspNetCore.Mvc;
[ApiController]
[Route("autocomplete")]
public class AutocompleteController : ControllerBase
{
    private readonly AutocompleteWrapper _wrapper;
    
    // Dependency injection
    public AutocompleteController(AutocompleteWrapper wrapper)
    {
        _wrapper = wrapper;
    }

    [HttpGet]
    public string[] Get(string prefix)
    {
        return _wrapper.TopWords(prefix); 
    }
}