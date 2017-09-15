#include <stdlib.h>
#include <stdio.h>
#include "combination_sum.h"

/** get_array
  *
  * Given an array A of size N, find the combination of M elements of the array
  * whose sum is equal to K.
  * @params:
  *     A: subarray of the current integers.
  *     size: the size of the (sub)array at this point (N).
  *     to_select: number of integers to be selected (M).
  *     goal: current number to match with sum (K).
  * @return:
  *     int * : array containing the to_select numbers that summed are equal to 'goal'.
*/
int * get_array(int * A, int size, int to_select, int goal) {
    if (to_select == 1) {
        int * result = calloc(sizeof(int), 1);
        int i;
        for (i = 0; i < size; i++) {
            if (goal == A[i]) {
                result[0] = A[i];
                return result;
            }
        }
        return NULL;
    }
    else {
        int * result = calloc(sizeof(int), to_select);
        int * partial_result;
        int current;
        for (current = 0; current < size; current++) {
            result = &A[current];
            partial_result = get_array(&A[current + 1], size - 1, to_select - 1, goal - A[current]);
            if ( partial_result ) {
                int i;
                for (i = 1; i < to_select; i++) {
                    result[i] = partial_result[i - 1];
                }
                return result;
            }
        }
        return NULL;
    }
}
