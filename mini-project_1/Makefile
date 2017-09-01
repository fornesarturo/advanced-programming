all:
	 gcc -c can_place_flowers.c
	 gcc -c main.c
	 gcc -o main.exe can_place_flowers.o main.o

test_can_place_flowers: clean
	 gcc -c can_place_flowers.c
	 gcc -c test_can_place_flowers.c
	 gcc -o test_can_place_flowers.exe can_place_flowers.o test_can_place_flowers.o
	 ./test_can_place_flowers.exe

test:	 test_can_place_flowers

clean:
	 rm *.out *.o *.exe *.gch || exit 0

run:
	 gcc -c can_place_flowers.c
	 gcc -c main.c
	 gcc -o main.exe can_place_flowers.o main.o
	 ./main.exe
