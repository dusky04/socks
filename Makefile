CC       = gcc
SRCDIR   = src
BUILDDIR = build
INCDIR   = -Iinclude
TARGET   = bin/flux
CFLAGS   = -Wall -Wextra -ggdb

SOURCES  = $(shell find $(SRCDIR) -type f -name '*.c')

OBJECTS  = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.c=.o))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking object files..."
	# @echo "$(CC) $(CFLAGS) $^ -o $(TARGET)"
	$(CC) $(CFLAGS) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@) 
	# @echo "Compiling $<..."
	# @echo "$(CC) $(CFLAGS) $(INCDIR) -c -o $@ $<"
	$(CC) $(CFLAGS) $(INCDIR) -c -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f $(BUILDDIR)/*.o
