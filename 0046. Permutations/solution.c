#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../C_library/library.h"

int **ret_val;
int current_row;
int *tmp_array;

void permute_r(int *nums, int numsSize, bool *chk_array, int remain_num) {
    for (int i = 0; i < numsSize; i++) {
        if (chk_array[i]) {
            chk_array[i] = false;
            tmp_array[numsSize - remain_num] = nums[i];
            if (remain_num == 1) {
                memcpy(ret_val[current_row++], tmp_array, sizeof(int)*numsSize);
            } else {
                permute_r(nums, numsSize, chk_array, remain_num-1);
            }
            chk_array[i] = true;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize) {
    *returnSize = 1;
    for (int i = numsSize; i > 0; i--) {
        *returnSize *= i;
    }
    ret_val = malloc(sizeof(int *) * (*returnSize));
    if (numsSize == 0) {
        ret_val[0] = NULL;
        return ret_val;
    }
    tmp_array = malloc(sizeof(int) * numsSize);
    bool chk_array[numsSize];
    current_row = 0;
    for (int i = 0; i < *returnSize; i++) {
        ret_val[i] = malloc(sizeof(int) * numsSize);
    }
    for (int i = 0; i < numsSize; i++) {
        chk_array[i] = true;
    }
    permute_r(nums, numsSize, chk_array, numsSize);
    free(tmp_array);
    return ret_val;
}

int main() {
    int nums[] = {1,2,3};
    int returnSize;
    int **ret_array = permute(nums, ARRAY_SIZE(nums), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < ARRAY_SIZE(nums); j++) {
            printf("%d ", ret_array[i][j]);
        }
        printf("\n");
        free(ret_array[i]);
    }
    free(ret_array);
    return 0;
}