using System;
//using CppCli
class Program
{
    static void Main()
    {
        var autocomplete = new AutocompleteWrapper();

        autocomplete.InsertWord("apple");
        autocomplete.InsertWord("applet");
        autocomplete.InsertWord("application");

        autocomplete.SelectWord("apple");
        autocomplete.SelectWord("application");
        autocomplete.SelectWord("application");
        autocomplete.SelectWord("application");

        var results = autocomplete.TopWords("app");

        foreach (var word in results)
        {
            Console.WriteLine(word);
        }
    }
}