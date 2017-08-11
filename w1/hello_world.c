// Geeting to know the argument vector.

#include <stdio.h>

int main(int argc, char ** argv) {
    int i;
    for (i = 1; i < argc; i++) {
        printf("Hello, %s \n", argv[i]);
    }

    return 0;
}
