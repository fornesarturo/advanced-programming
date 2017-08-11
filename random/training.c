#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	// Variable declaration.
    char *string = (char *) malloc(sizeof(char));

	// Body.
	*string = 'a';
    printf("Size of string is: %lu \n", sizeof(string));
	printf("The value of string, which is *string is: %c \n", *string);

    // Let's see the size of the variables.
    printf("Char: %lu\nInt: %lu\nFloat: %lu\nDouble: %lu\n", sizeof(char), sizeof(int), sizeof(float), sizeof(double));

	// Post-Execution.
	free(string);

	printf("string value is now:'%c' after freeing the variable. \n", *string);

	// End.
	return 0;
}
