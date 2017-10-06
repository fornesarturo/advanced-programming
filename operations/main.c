#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#define MAX_LENGTH 10
#define print_debug(msg) do { char * value = getenv("OPER_DEBUG"); if( value != NULL && !strcmp(value, "t") ) printf("%s", msg); } while(0)

// To set the respective environment variables:
//  export OPER_DEBUG=t
//  export OPER_LANG=EN

char * operation_names_ES[] = {"suma", "resta"};
char * operation_names_EN[] = {"add", "subtract"};
char * messages_ES[] = {"¿Cual es la operacion?"};
char * messages_EN[] = {"What is the operation?"};

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main(int argc, char **argv) {
	char * operation_name;
    char message[200];
	int operator1, operator2;
    int (* operation)(int, int);
    char * lang;
    char ** operation_names;
    char ** messages;

    lang = getenv("OPER_LANG");

    if( lang != NULL && !strcmp(lang, "EN")) {
        operation_names = operation_names_EN;
        messages = messages_EN;
    }
    else {
        operation_names = operation_names_ES;
        messages = messages_ES;
    }

    operation_name = malloc(sizeof(char) * MAX_LENGTH);
    printf("%s\n", messages[0]);
	scanf("%s", operation_name);
	scanf("%d", &operator1);
	scanf("%d", &operator2);
	sprintf(message, "operation_name = %s\n", operation_name);
	print_debug(message);
	sprintf(message, "operator1 = %d  operator2 = %d\n", operator1, operator2);
	print_debug(message);

    if(!strcmp(operation_name, operation_names[0])) {
        operation = add;
    }

    if(!strcmp(operation_name, operation_names[1])) {
        operation = subtract;
    }

	printf("%d\n", operation(operator1, operator2));
    return 0;
}
