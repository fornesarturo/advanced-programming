#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ransom_note.h"

int canConstruct(char * ransom_note, char * magazine) {
    char * copy_ransom;
    // strcpy(copy_ransom, ransom_note);
    copy_ransom = strdup(ransom_note);
    char * current;
    int i;
    for (current = magazine; *current != '\0'; current++) {
        printf("%c\n", *current);
        for (i = 0; copy_ransom[i] != '\0'; i++) {
            printf("%c\n", copy_ransom[i]);
            if(*current == copy_ransom[i]) {
                printf("Equality: %d\n", *current == copy_ransom[i]);
                copy_ransom[i] = '*';
                break;
            }
        }
    }
    printf("Final String: %s\n", copy_ransom);
    for (i = 0; copy_ransom[i] != '\0'; i++) {
        if(copy_ransom[i] != ' ' && copy_ransom[i] != '*') {
            printf("Condition %d && %d = %d", copy_ransom[i] != " ", copy_ransom[i] != "*", copy_ransom[i] != " " && copy_ransom[i] != "*");
            printf("Cannot be formed, *current = %c, at index %d\n", copy_ransom[i], i);
            free(copy_ransom);
            return 0;
        }
    }
    free(copy_ransom);
    printf("Can be formed!\n");
    return 1;
}
