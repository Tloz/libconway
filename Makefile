CC=g++
CFLAGS=--std=c++1z
LDFLAGS=-Lbin
CFLAGSSTRICT=-W -Wall -Wextra -pedantic
CFLAGSSUPERSTRICT=-Werror
CFLAGSCHEAT=-fpermissive -Wunused-variable
CFLAGSOPT=-O3

all: libconway tests

init:
	@mkdir tmp bin out lib 2>/dev/null

libconway: out/libconway.a

out/libconway.a: obj/cell.o obj/world.o
	ar rcs $@ $^

header: inc/version.h inc/cell.h inc/world.h
	@cat $^ > tmp/libconway.h


archive: libconway header version LICENSE
	@mv tmp/libconway.h inc/libconway.h
	@ln out/libconway.a libconway.a
	tar -czf out/libconway.v$(shell ./bin/version).tar.gz LICENSE libconway.a inc/*.h
	@rm -rf inc/libconway.h
	@rm libconway.a

tests: version cell world

######### PARTS ########
obj/version.o: src/version.cpp inc/version.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/cell.o: src/cell.cpp inc/cell.h
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)

obj/world.o: src/world.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(CFLAGSSTRICT)


######### TESTS ########
version: obj/version.o tests/version.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

cell: obj/cell.o tests/cell.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)

world: obj/world.o tests/world.cpp
	$(CC) $^ -o bin/$@ $(CFLAGS) $(CFLAGSSTRICT)


.PHONY: clean mrproper
 
clean:
	@rm -rf *.o
	@rm -rf obj/*.o

mrproper: clean
	@rm -rf bin/*
	@rm -rf out/*
	@rm -rf libconway.*
