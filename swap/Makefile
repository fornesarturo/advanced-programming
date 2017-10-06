LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c swap.c
	 gcc -c main.c
	 gcc -o main.exe swap.o main.o

test_swap: clean
	 gcc -c swap.c
	 gcc -c test_swap.c
	 gcc -o test_swap.exe swap.o test_swap.o
	 ./test_swap.exe

test:	 test_swap

clean:
	 rm *.out *.o *.exe *.gch || exit 0

run:
	 gcc -c swap.c
	 gcc -c main.c
	 gcc -o main.exe swap.o main.o
	 ./main.exe
