OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

build: $(OBJECTS)
	mkdir -p lib
	gcc -shared $(OBJECTS) -o lib/easeC.so

build/%.o: src/%.c
	mkdir -p build
	gcc -fPIC -Wall -Wextra -Iheader -c $< -o $@

clean:
	rm -rf build lib
