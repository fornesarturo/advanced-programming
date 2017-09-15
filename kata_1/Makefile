CC = gcc
CFLAGS = -I.
DEPS = last_word_len.h
OBJ = last_word_len.o last_word_len_main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

last_word_len.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

run: $(OBJ)
	$(CC) -o last_word_len.exe $^ $(CFLAGS)
	./last_word_len.exe

clean:
	rm *.o *.exe *.gch
