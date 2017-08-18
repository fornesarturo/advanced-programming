#include <stdio.h>
#include "last_word_len.h"

int main(int argc, char **argv) {
    char * phrase = "Hola Mundo como estamos todos";
    int len = last_word_len(phrase, 29);
    printf("De la frase: \"%s\" la última palabra tiene longitud: %d\n", phrase, len);

    return 0;
}
