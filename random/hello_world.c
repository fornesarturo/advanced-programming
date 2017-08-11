#include <stdio.h>
#include <stdlib.h>

int main() {
	// Variable declaration.
    char *string = malloc(sizeof(char));

	// Body.
	*string = 'a';
    printf("Size of string is: %lu \n", sizeof(string));
	printf("The value of string, which is *string is: %c \n", *string);

	// Post-Execution.
	free(string);

	printf("string value is now:'%c' after freeing the variable. \n", *string);

	// End.
	return 0;
}
