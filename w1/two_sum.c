// Problem 'Two Sum' from Leetcode at: https://leetcode.com/problems/two-sum/description/

#include <stdio.h>
#include <stdlib.h>

int * two_sum (int * nums, int num_size, int target) {
    // You have to check each combination in case of negative numbers.
    int i, j;
    int * result = (int *) calloc(2, sizeof(int));
    for (i = 0; i < num_size - 1; i++) {
        for (j = i + 1; j < num_size; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i; result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main (int argc, char ** argv) {
    int nums[] = {-1, -2, -3, -4, -5};
    int target = -8, num_size = 5;
    int *result = two_sum(nums, num_size, target);
    if(result != NULL && nums[result[0]] + nums[result[1]] == target) {
        printf("[%d, %d] = %d \n", result[0], result[1], nums[result[0]] + nums[result[1]]);
        printf("It was true! \n");
    } else {
        printf("It lied! The MACHINE lied! \n");
    }
    free(result);
    return 0;
}
