CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/gameboy_emulator

SRCEXT := cpp
# Find all cpp files in src directory and its subdirectories
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
# Create mirrored source names under build dir
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g # -Wall
LIB := -L lib -L /usr/lib/x86_64-linux-gnu -lglfw -lGLEW -lGL -lGLU -lOpenGL
INC := -I include

RM=/bin/rm

# Main executable, depends on object files
$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@echo "$(OBJECTS)"
	@echo "$(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

# Rule for object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	@echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..."; 
	@echo "$(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
test:
	$(CC) $(CFLAGS) test/test.cpp $(INC) $(LIB) -o bin/test

# In case we have a file named 'clean'
.PHONY: clean