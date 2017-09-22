#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minunit.h"
#include "dict.h"

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

static char *test_init_dictionary () {
    unsigned int size = 4;
    int error_code;
    Dictionary *my_dictionary = init_dict(size, &error_code);
    mu_assert("my_dictionary size must be 4", my_dictionary->size == 4);
    mu_assert("my_Dictionary errorCode must be 0", error_code == 0);
    return 0;
}

static char *test_upsert_dictionary () {
    unsigned int size = 1;
    int error_code;
    Dictionary *my_dictionary = init_dict(size, &error_code);
    int value = 1;
    upsert_dict(my_dictionary, "uno", (void *) &value, sizeof(int), &error_code);
    mu_assert("my_dictionary error_code must be 0", error_code == 0);
    mu_assert("my_dictionary error_code must be 0", strcmp(my_dictionary->elements[0].key, "uno") == 0);
    mu_assert("my_dictionary error_code must be 0", *((int *) my_dictionary->elements[0].value) == value);
    return 0;
}

static char *test_get_dictionary () {
    unsigned int size = 1;
    int error_code;
    Dictionary *my_dictionary = init_dict(size, &error_code);
    int value = 1;
    upsert_dict(my_dictionary, "uno", (void *) &value, sizeof(int), &error_code);
    void *result = get_dict(my_dictionary, "uno", sizeof(int), &error_code);
    value = 27;
    mu_assert("my_dictionary error_code must be 0", error_code == 0);
    printf("%d\n", *((int *)result));
    mu_assert("result must be equal to value", *((int *) result) == 1);
    return 0;
}

static char *test_get_dictionary_null () {
    unsigned int size = 100;
    int error_code;
    Dictionary *my_dictionary = init_dict(size, &error_code);
    int value = 1;
    upsert_dict(my_dictionary, "uno", (void *) &value, sizeof(int), &error_code);
    void *result = get_dict(my_dictionary, "dos", sizeof(int), &error_code);
    value = 27;
    mu_assert("my_dictionary error_code must be 0", error_code == 0);
    mu_assert("result must be equal to NULL", result == NULL);
    return 0;
}

static char *all_tests () {
    mu_run_test(test_init_dictionary);
    mu_run_test(test_upsert_dictionary);
    mu_run_test(test_get_dictionary);
    mu_run_test(test_get_dictionary_null);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
      printf("-_-_-_-_-_-_-_,------,      o \n");
      printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
      printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
      printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
      printf(KRED "✗ %s \n" RESET, result);
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
