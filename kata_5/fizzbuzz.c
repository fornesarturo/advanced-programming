#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fizzbuzz.h"

/** fizzbuzz
  *
  * Given an integer n, output the string representation of number 1 through n.
  * For multiples of three, instead, output 'Fizz', likewise for multiples of
  * five, output 'Buzz', and for both output 'FizzBuzz'.
  * @param:
  *   n - limit number
  * @return:
  *   (maybe) char ** - list of strings of the series.
**/
void fizzbuzz (int n) {
    int i;
    char print[11];
    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            if (i % 5 != 0)
                strcpy(print, "Fizz");
            else if (i % 3 != 0)
                strcpy(print, "Buzz");
            else
                strcpy(print, "FizzBuzz");
        else
            sprintf(print, "%d", i);
        printf("%s\n", print);
    }
}
