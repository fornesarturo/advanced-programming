#include <stdio.h>
#include "minunit.h"
#include "calculate_days.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testUnit() {
    Month month = Feb;
    int month_day = 28;
    int expected = 31 + 28;
    int result = calculate_days(month_day, month, 2017);
    muAssert("error, testUnit result != expected", result == expected);
    return 0;
}

static char * testLeap() {
    int year = 2017;
    int expected = 0;
    int result = is_leap_year(year);
    muAssert("error, testUnit result != expected", result == expected);
    return 0;
}

static char * allTests() {
    muRunTest(testUnit);
    muRunTest(testLeap);
    return 0;
}

int main(int argc, char **argv) {
    char *result = allTests();
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
    printf("Tests run: %d\n", testsRun);
    return result != 0;
}
