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
  *   n - limit number.
  *   return_size - size of the returning char ** .
  * @return:
  *   char ** - list of strings of the series.
**/
char ** fizzbuzz (int n, int * return_size) {
    int i;
    char print[11];
    char ** result = (char **) malloc(sizeof(char * ) * n);
    for (i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            if (i % 5 != 0) {
                strcpy(print, "Fizz");
                result[i - 1] = (char *) malloc(sizeof(char) * 5);
            }
            else if (i % 3 != 0) {
                strcpy(print, "Buzz");
                result[i - 1] = (char *) malloc(sizeof(char) * 5);
            }
            else {
                strcpy(print, "FizzBuzz");
                result[i - 1] = (char *) malloc(sizeof(char) * 9);
            }
        }
        else {
            sprintf(print, "%d", i);
            result[i - 1] = (char *) malloc(sizeof(char) * strlen(print));
        }
        strcpy(result[i - 1], print);
    }
    *return_size = n;
    return result;
}
