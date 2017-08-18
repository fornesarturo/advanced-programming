CC = gcc
CFLAGS = -I.
DEPS = two_sum.h
OBJ = two_sum.o two_sum_main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

two_sum.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o *.exe
