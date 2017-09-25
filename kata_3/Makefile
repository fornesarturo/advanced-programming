all:
-e 	 gcc -c keyboard_row.c
-e 	 gcc -c main.c
-e 	 gcc -o main.exe keyboard_row.o main.o

test_keyboard_row: clean
-e 	 gcc -c keyboard_row.c
-e 	 gcc -c test_keyboard_row.c
-e 	 gcc -o test_keyboard_row.exe keyboard_row.o test_keyboard_row.o
-e 	 ./test_keyboard_row.exe

-e test:	 test_keyboard_row

clean:
-e 	 rm *.out *.o *.exe *.gch || exit 0

run:
-e 	 gcc -c keyboard_row.c
-e 	 gcc -c main.c
-e 	 gcc -o main.exe keyboard_row.o main.o
-e 	 ./main.exe
