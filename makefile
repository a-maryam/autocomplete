CXX      := g++
CXXFLAGS := -Wall -std=c++17 -Iinclude
TARGET   := autocomplete

SRCDIR := src
OBJDIR := obj
BINDIR := bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJS    := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
TARGET_PATH := $(BINDIR)/$(TARGET)

all: $(TARGET_PATH)

# only rebuild binary if objects change
$(TARGET_PATH): $(OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# only rebuild object if source changes
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure directories exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
