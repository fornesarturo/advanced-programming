#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "reverse_string.h"

#define print_debug(msg) do { \
	char * value = getenv("REVERSE_DEBUG");\
	if (value != NULL && !strcmp(value, "t")) printf("%s", msg);\
} while(0);


int main(int argc, char **argv) {
	
	char string[40];
	char message[40];

	printf("Enter the string you want reversed: \n");
	scanf("%s", string);
	
	sprintf(message, "string=%s\n", string);
	print_debug(message);

	char * reverse = reverse_string(string);

	if (reverse != NULL) {
		printf("Reversed: %s\n", reverse);	
	}
	
	return 0;
}
