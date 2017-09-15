#include <stdlib.h>
#include <stdio.h>
#include "combination_sum.h"

int main(int argc, char **argv) {
    printf("\nHello, there. This is the main class!\n");
    int array[] = {4,3,5,6,8,16};
    int N = 6;
    int M = 4;
    int K = 33;
    int * result;
    if (result = get_array(array, N, M, K) ) {
        int i;
        printf("The combination of %d values that when summed result in %d in the array: ", M, K);
        printf(" [ ");
        for (i = 0; i < N; i++) {
            printf("%d ", array[i]);
        }
        printf("] is:\n");
        for (i = 0; i < M; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    };

    return 0;
}
