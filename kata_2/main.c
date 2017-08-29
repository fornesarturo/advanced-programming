#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ransom_note.h"

/* Add function signatures here */

int main(int argc, char **argv) {
    /* Start your code here */
    printf("Hello from main\n");
    char * src = "Hey";
    char * dest;

    strcpy(dest, src);

    printf("%s\n",dest);

    free(dest);
    free(src);
    return 0;
}
