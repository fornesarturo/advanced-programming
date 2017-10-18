#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "reverse_string.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int tests_run = 0;

static char * test_odd() {
	char * string = "hello";
	char * reverse = reverse_string(string);
	mu_assert("Wrong string!", reverse != NULL && string[0] == reverse[4] && string[1] == reverse[3] && string[2] == reverse[2]);
	mu_assert("Wrong string!", reverse != NULL && string[3] == reverse[1] && string[4] == reverse[0]);
	return 0;
}

static char * test_even() {
	char * string = "greeting";
	char * reverse = reverse_string(string);
	printf("Reverse: %s\n", reverse);
	mu_assert("Wrong string!", reverse != NULL && string[0] == reverse[7]);
	mu_assert("Wrong string!", reverse != NULL && string[1] == reverse[6]);
	mu_assert("Wrong string!", reverse != NULL && string[2] == reverse[5]);
	mu_assert("Wrong string!", reverse != NULL && string[3] == reverse[4]);
	return 0;
}

static char * test_1_char() {
	char * string = "hi";
	char * reverse = reverse_string(string);
	printf("Reverse: %s\n", reverse);
	mu_assert("Wrong string!", reverse != NULL && reverse[0] == string[1]);
	mu_assert("Wrong string!", reverse != NULL && reverse[1] == string[0]);
	return 0;
}

static char * test_empty() {
	char * string = "";
	char * reverse = reverse_string(string);
	mu_assert("Wrong string!", reverse != NULL && reverse[0] == string[0] && reverse[0] == '\0');
	return 0;
}

static char * all_tests() {
	mu_run_test(test_odd);
	mu_run_test(test_even);
	mu_run_test(test_1_char);
	mu_run_test(test_empty);
	return 0;
}
int main(int argc, char **argv) {
	char *result = all_tests();
	if (result != 0) {
		printf("-_-_-_-_-_-_-_,------,      o \n");
		printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
		printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
		printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
		printf(KRED "✗ %s\n" RESET, result);
	}
	else {
		printf("-_-_-_-_-_-_-_,------,      o \n");
		printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
		printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
		printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
		printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}
