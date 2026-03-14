var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring OpenAPI at https://aka.ms/aspnet/openapi
builder.Services.AddOpenApi();
builder.Services.AddControllers();
builder.Services.AddSingleton<AutocompleteWrapper>();
var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.MapOpenApi();
}

app.UseHttpsRedirection();
app.MapControllers();

app.Run();

/*var wrapper = new AutocompleteWrapper();

app.MapGet("/autocomplete", (string prefix) =>
{
    return wrapper.TopWords(prefix);
});

app.Run();*/


// operations 
// get autocomplete
