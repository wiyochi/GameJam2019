SRCDIR := src
BUILDDIR := build
TARGET := bin/run.out
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -g3 -O0 -Wall -Wextra

CC := g++ -std=c++17
LIBPATHS := -L./lib/SFML-2.5.1/lib
LIBFLAGS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INC := -Iinclude/ -I./lib/SFML-2.5.1/include

$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CC) $^ -o $(TARGET) $(LIBPATHS) $(LIBFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

# Cleaning
clean:
	@rm -rf $(BUILDDIR) $(TARGET)

# Running
run:
	@export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:./lib/SFML-2.5.1/lib; ./$(TARGET)

# Running
valgrind:
	@export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:./lib/SFML-2.5.1/lib; valgrind ./$(TARGET)

build-and-run:
	@make
	@make run

.PHONY: clean