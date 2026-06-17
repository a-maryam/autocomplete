using System.Diagnostics.Metrics;

public class AutocompleteMetrics
{
    private readonly Counter<long> _queryCount;
    private readonly Histogram<int> _prefixLength;
    private readonly Histogram<int> _suggestionsReturned;
    private readonly Counter<long> _frequencyIncrements;
    private readonly Histogram<double> _trieLookupDuration;
    private readonly Histogram<double> _naiveLookupDuration;

    public AutocompleteMetrics(IMeterFactory meterFactory)
    {
        var meter = meterFactory.Create("autocomplete");
        _queryCount = meter.CreateCounter<long>("autocomplete.queries.total", description: "Total autocomplete queries");
        _prefixLength = meter.CreateHistogram<int>("autocomplete.query.prefix_length", description: "Length of query prefix");
        _suggestionsReturned = meter.CreateHistogram<int>("autocomplete.suggestions.returned", description: "Number of suggestions returned per query");
        _frequencyIncrements = meter.CreateCounter<long>("autocomplete.frequency.increments.total", description: "Total word frequency increments (word selections)");
        _trieLookupDuration = meter.CreateHistogram<double>("autocomplete.trie_lookup_duration_ms", unit: "ms", description: "C++ trie lookup duration in milliseconds");
        _naiveLookupDuration = meter.CreateHistogram<double>("autocomplete.naive_lookup_duration_ms", unit: "ms", description: "Naive C# linear scan duration in milliseconds");
    }

    public void RecordQuery(int prefixLen, int suggestionsCount, double trieMs)
    {
        _queryCount.Add(1);
        _prefixLength.Record(prefixLen);
        _suggestionsReturned.Record(suggestionsCount);
        _trieLookupDuration.Record(trieMs);
    }

    public void RecordNaiveLookup(double naiveMs)
    {
        _naiveLookupDuration.Record(naiveMs);
    }

    public void RecordFrequencyIncrement()
    {
        _frequencyIncrements.Add(1);
    }
}
