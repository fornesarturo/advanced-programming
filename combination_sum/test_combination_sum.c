#include <stdio.h>
#include "minunit.h"
#include "combination_sum.h"

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

static char * test_unit() {
    int array[] = {4,3,5,6,8,16};
    int N = 6;
    int M = 4;
    int K = 4 + 5 + 8 + 16;
    int * result;
    result = get_array(array, N, M, K);
    mu_assert("Wrong numbers!", result[0] == 4 && result[1] == 5 && result[2] == 8 && result[3] == 16);
    return 0;
}

static char * test_simple() {
    int array[] = {4,3,5,6,8,16};
    int N = 6;
    int M = 2;
    int K = 5 + 16;
    int * result;
    result = get_array(array, N, M, K);
    mu_assert("Wrong numbers!", result[0] == 5 && result[1] == 16);
    return 0;
}

static char * test_base() {
    int array[] = {4,3,5,6,8,16};
    int N = 6;
    int M = 1;
    int K = 8;
    int * result;
    result = get_array(array, N, M, K);
    mu_assert("Bad base case!", result[0] == 8);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_unit);
    mu_run_test(test_base);
    mu_run_test(test_simple);
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
