#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "reverse_string.h"

char * reverse_string(char * string) {
	if (string == NULL || *string == '\0') {
		return string;
	}

	char * modifiable_string = strdup(string);
	char * last = modifiable_string;
	int size = 0, i;
	char tmp;

	for (; *last != '\0'; last++) {
		size++;
	}

	last--;
	
	if (size == 1) {
		return string;
	}

	for (i = 0; i < size/2; i++) {
		tmp = *last;
	   	*last = modifiable_string[i];
		modifiable_string[i] = tmp;
		last--;
	}

	return modifiable_string;
}
