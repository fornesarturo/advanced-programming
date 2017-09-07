#include <stdlib.h>
#include <stdio.h>
#include "can_place_flowers.h"

int main(int argc, char **argv) {
    int flowerbed[] = {1,0,1,0,0,0,1,0,0};
    int flowerbed_size = 9;
    int n = 3, i, f_counter;
    int result = can_place_flowers(flowerbed, flowerbed_size, n);

    // The following monster of code is to print a 'report' of the given case.
    // It includes where the flowers were placed or could have been placed and
    // whether n flowers where able to be planted.
    printf("\n\n\nResult is %d\n", result);
    if (result) {
        f_counter = n;
        printf("You're able to place %d flowers in the flowerbed: \n", n);
        for (i = 0; i < flowerbed_size; i++) {
            printf(" %d ", flowerbed[i]);
        }
        printf("\n\nThese are the following places in which a flower was placed, denoted by F:\n");
        for(i = 0; i < flowerbed_size; i++) {
            if( i == 0 ) {
                if(flowerbed[i + 1] == 0 && flowerbed[i] == 0 && f_counter > 0) {
                    printf(" F ");
                    f_counter--;
                } else {
                    printf(" %d ", flowerbed[i]);
                }
            }
            else if( i == flowerbed_size - 1 ) {
                if(flowerbed[i - 1] == 0 && f_counter > 0) {
                    printf(" F ");
                    f_counter--;
                } else {
                    printf(" %d ", flowerbed[i]);
                }
            }
            else if(flowerbed[i] == 0) {
                if(flowerbed[i - 1] == 0 && flowerbed[i+1] == 0 && f_counter > 0) {
                    printf(" F ");
                    f_counter--;
                } else {
                    printf(" %d ", flowerbed[i]);
                }
            }
            else {
                printf(" %d ", flowerbed[i]);
            }
        }

        printf("\n\n");
    }
    else {
        printf("You're not able to place %d flowers in the flowerbed", n);
        printf("\n\nThese are the following places in which you can place a flower, denoted by F:\n");
        for(i = 0; i < flowerbed_size; i++) {
            if( i == 0 ) {
                if(flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                    printf(" F ");
                } else {
                    printf(" %d ", flowerbed[i]);
                }
            }
            else if( i == flowerbed_size - 1 ) {
                if(flowerbed[i - 1] == 0) {
                    printf(" F ");
                } else {
                    printf(" %d ", flowerbed[i]);
                }
            }
            else if(flowerbed[i] == 0) {
                if(flowerbed[i - 1] == 0 && flowerbed[i+1] == 0) {
                    printf(" F ");
                } else {
                    printf(" %d ", flowerbed[i]);
                }
            }
            else {
                printf(" %d ", flowerbed[i]);
            }
        }

        printf("\n\n");
    }
    return 0;
}
