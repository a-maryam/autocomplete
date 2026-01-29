CXX      := g++
CXXFLAGS := -Wall -std=c++17 -Iinclude 
TARGET   := autocomplete

SRCDIR := src  
OBJDIR := obj

# Get all source files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)

# Transform src/*.cpp paths to obj/*.o paths
OBJS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile objects from the source dir into the object dir
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
