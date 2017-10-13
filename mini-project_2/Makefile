LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c reverse_string.c
	 gcc -c main.c
	 gcc -o reverse_string.exe reverse_string.o main.o $(LIB)

test_reverse_string: clean
	 gcc -c reverse_string.c
	 gcc -c test_reverse_string.c
	 gcc -o test_reverse_string.exe reverse_string.o test_reverse_string.o
	 ./test_reverse_string.exe

test:	 test_reverse_string

clean:
	 rm *.out *.o *.exe || exit 0

reverse_string: clean
	 gcc -c reverse_string.c
	 gcc -c main.c
	 gcc -o reverse_string.exe reverse_string.o main.o $(LIB)

run: reverse_string
	 ./reverse_string.exe

runtest: reverse_string
	 ./integrationtest.tcl ./reverse_string.exe

