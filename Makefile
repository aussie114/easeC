OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

# Default target
all: lib/libeaseC.a

# Static library target
lib/libeaseC.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)

# Compile object files
build/%.o: src/%.c
	gcc -Wall -Wextra -Iheader -c $< -o $@

# Clean build artifacts
clean:
	rm -rf build/* lib/*
