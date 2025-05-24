OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

build: $(OBJECTS)
	gcc -c build/*.o -o ./lib/easeC.lib

build/string.o: src/string.c
	gcc -c -Iheader src/string.c -o build/string.o

build/random.o: src/random.c
	gcc -c -Iheader src/random.c -o build/random.o

clean:
	rm build/*o ./lib/easeC
