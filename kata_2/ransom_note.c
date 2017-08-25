#include <stdlib.h>
#include <stdio.h>
#include "ransom_note.h"

int canConstruct(char * ransom_note, char * magazine) {
    char *current;
    for (current = magazine; *current != '\0'; current++) {
        printf("%c\n", *current);
        for (int i = 0; ransom_note[i] != '\0'; i++) {
            if(*current == ransom_note[i]) {
                ransom_note[i] = '*';
            }
        }
    }
    printf("Final String: %s\n", ransom_note);
    return 0;
}
