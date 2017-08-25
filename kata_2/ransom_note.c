#include <stdlib.h>
#include <stdio.h>
#include "ransom_note.h"

int canConstruct(char * ransom_note, char * magazine) {
    char *current;
    int i;
    for (current = magazine; *current != '\0'; current++) {
        printf("%c\n", *current);
        for (i = 0; ransom_note[i] != '\0'; i++) {
            printf("%c\n", ransom_note[i]);
            if(*current == ransom_note[i]) {
                printf("Equality: %d\n", *current == ransom_note[i]);
                ransom_note[i] = '*';
            }
        }
    }
    printf("Final String: %s\n", ransom_note);
    return 0;
}
