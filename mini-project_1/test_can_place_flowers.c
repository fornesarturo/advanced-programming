#include <stdio.h>
#include "minunit.h"
#include "can_place_flowers.h"

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

static char * test_base_case() {
    int flowerbed_base[] = {1,0,0};
    int flowerbed_base_size = 3;
    int n = 1;
    int result;
    result = can_place_flowers(flowerbed_base, flowerbed_base_size, n);
    mu_assert("Base case should be true", result == 1);
    return 0;
}

static char * test_base_case_2() {
    int flowerbed_base[] = {1,0,0,1};
    int flowerbed_base_size = 4;
    int n = 1;
    int result;
    result = can_place_flowers(flowerbed_base, flowerbed_base_size, n);
    mu_assert("Base case should be false", result == 0);
    return 0;
}

static char * test_edge_case() {
    int flowerbed[] = {0,0,1,0,0};
    int flowerbed_size = 5;
    int n = 2;
    int result;
    result = can_place_flowers(flowerbed, flowerbed_size, n);
    mu_assert("You should be able to place flowers", result == 1);
    return 0;
}

static char * test_edge_case_2() {
    int flowerbed[] = {1,0,1,0,1,0,0};
    int flowerbed_size = 7;
    int n = 1;
    int result;
    result = can_place_flowers(flowerbed, flowerbed_size, n);
    mu_assert("You should be able to place flowers", result == 1);
    return 0;
}

static char * all_tests() {
    mu_run_test(test_base_case);
    mu_run_test(test_base_case_2);
    mu_run_test(test_edge_case);
    mu_run_test(test_edge_case_2);
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
