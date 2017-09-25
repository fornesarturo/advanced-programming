#include <stdio.h>
#include "minunit.h"
#include "keyboard_row.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "[0m"

int tests_run = 0;

static char * test_unit() {
    mu_assert("error, testUnit 1 != 1", 1 == 1);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_unit);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
      printf("-_-_-_-_-_-_-_,------,      o 
");
      printf("_-_-_-_-_-_-_-|   /\_/\ 
");
      printf("-_-_-_-_-_-_-~|__( X .X)  +     + 
");
      printf("_-_-_-_-_-_-_- \"\"  \"\" 
");
      printf(KRED "✗ %s 
" RESET, result);
    }
    else {
      printf("-_-_-_-_-_-_-_,------,      o 
");
      printf("_-_-_-_-_-_-_-|   /\_/\ 
");
      printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + 
");
      printf("_-_-_-_-_-_-_-  \"\"  \"\" 
");
      printf(KGRN " ✓ ALL TESTS PASSED 
" RESET);
    }
    printf("Tests run: %d
", tests_run);
    return result != 0;
}
