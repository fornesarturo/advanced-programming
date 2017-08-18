all:
	 gcc -c two_sum.c
	 gcc -c main.c
	 gcc -o main two_sum.o main.o

test_two_sum: clean
	 gcc -c two_sum.c
	 gcc -c test_two_sum.c
	 gcc -o test_two_sum.exe two_sum.o test_two_sum.o
	 ./test_two_sum.exe

test:	 test_two_sum

clean:
	 rm *.out *.o *.exe || exit 0

run:
	 gcc -c two_sum.c
	 gcc -c main.c
	 gcc -o main.exe two_sum.o main.o
	 ./main
