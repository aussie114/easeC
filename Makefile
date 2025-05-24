OBJECTS = $(patsubst src/%.c, build/%.o, $(wildcard src/*.c))

build: $(OBJECTS)
	gcc -c build/*.o -o ./lib/easeC

build/string.o: src/string.c
	gcc -c -Iheader src/string.c -o build/string.o

clean:
	rm build/*o ./lib/easeC
