LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c text.c
	 gcc -c main.c
	 gcc -o text.exe text.o main.o $(LIB)

test_text: clean
	 gcc -c text.c
	 gcc -c test_text.c
	 gcc -o test_text.exe text.o test_text.o
	 ./test_text.exe

test:	 test_text

clean:
	 rm *.out *.o *.exe || exit 0

text: clean
	 gcc -c text.c
	 gcc -c main.c
	 gcc -o text.exe text.o main.o $(LIB)

run: text
	 ./text.exe

runtest: text
	 ./integrationtest.tcl ./text.exe

