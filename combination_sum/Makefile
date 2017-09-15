all:
	 gcc -c combination_sum.c
	 gcc -c main.c
	 gcc -o main.exe combination_sum.o main.o

test_combination_sum: clean
	 gcc -c combination_sum.c
	 gcc -c test_combination_sum.c
	 gcc -o test_combination_sum.exe combination_sum.o test_combination_sum.o
	 ./test_combination_sum.exe

test:	 test_combination_sum

clean:
	 rm *.out *.o *.exe *.gch || exit 0

run:
	 gcc -c combination_sum.c
	 gcc -c main.c
	 gcc -o main.exe combination_sum.o main.o
	 ./main.exe
