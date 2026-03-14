using Microsoft.AspNetCore.Mvc;
[ApiController]
[Route("autocomplete")]
public class AutocompleteController : ControllerBase
{
    private readonly AutocompleteWrapper _wrapper;

    public AutocompleteController()
    {
        _wrapper = new AutocompleteWrapper();
    }

    [HttpGet]
    public string[] Get(string prefix)
    {
        return _wrapper.TopWords(prefix);
    }
}