#include <stdlib.h>
#include <stdio.h>
#include "text.h"

/* Add function signatures here */

int main(int argc, char **argv) {
    FILE *myFile;
    assert(argc == 2);
    myFile = fopen(argv[1], "r");
    assert(myFile == NULL);

    return 0;
}
