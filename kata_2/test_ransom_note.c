#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "ransom_note.h"

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

static char * test_construct_1 () {
    char  *ransom_note_test = "hola amigoso";
    char * magazine_test = "alohsogmio";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this result should be true.", result == 1);
    return 0;
}

static char * test_construct_0 () {
    char * ransom_note_test = "help me pls";
    char * magazine_test = "";
    int result = can_construct(ransom_note_test, magazine_test);
    mu_assert("Error, this result should be false.", result == 0);
}

static char * all_tests () {
    mu_run_test(test_construct_1);
    return 0;
}

int main (int argc, char **argv) {
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
