var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
// Learn more about configuring OpenAPI at https://aka.ms/aspnet/openapi
builder.Services.AddOpenApi();

//builder.Services.AddSingleton<AutocompleteWrapper>();
builder.Services.AddSingleton<AutocompleteWrapper>(serviceProvider =>
{
    var wrapper = new AutocompleteWrapper();
    wrapper.LoadLexicon("Data/google-10000-english.txt"); // load once
    return wrapper;
});

builder.Services.AddControllers();

// for React
builder.Services.AddCors(options =>
{
    options.AddPolicy("AllowViteDev",
        policy => policy
            .WithOrigins("http://localhost:5173")
            .AllowAnyHeader()
            .AllowAnyMethod());
});

var app = builder.Build();

// Configure the HTTP request pipeline.
if (app.Environment.IsDevelopment())
{
    app.MapOpenApi();
}

// for react /vite
app.UseCors("AllowViteDev");
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
