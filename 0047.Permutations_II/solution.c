#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "../C_library/library.h"

int compare_func(const void *num1, const void *num2) {
    if (*(int *)num1 > *(int *)num2)
        return 1;
    else if (*(int *)num1 < *(int *)num2)
        return -1;
    else
        return 0;
}

int **ret_array;
int current_row;
int max_row;

void permuteUnique_r(int* nums, int numsSize, bool *chk_array, int *tmp_array, int remain_num) {
    int tmp_val = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (tmp_val != INT_MIN && nums[i] == tmp_val)
            continue;
        if (chk_array[i]) {
            chk_array[i] = false;
            tmp_array[numsSize - remain_num] = tmp_val = nums[i];
            if (remain_num == 1) {
                if (current_row == max_row) {
                    max_row *= 2;
                    ret_array = realloc(ret_array, sizeof(int *) * max_row);
                }
                ret_array[current_row] = malloc(sizeof(int) * numsSize);
                memcpy(ret_array[current_row++], tmp_array, sizeof(int) * numsSize);
            } else {
                permuteUnique_r(nums, numsSize, chk_array, tmp_array, remain_num-1);
            }
            chk_array[i] = true;
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        return NULL;
    }
    max_row = 10;
    current_row = 0;
    ret_array = malloc(sizeof(int *) * max_row);
    qsort(nums, numsSize, sizeof(int), compare_func);
    bool chk_array[numsSize];
    int tmp_array[numsSize];
    for (int i = 0; i < numsSize; i++) {
        chk_array[i] = true;
    }
    permuteUnique_r(nums, numsSize, chk_array, tmp_array, numsSize);
    *returnSize = current_row;
    return ret_array;
}

int main() {
    int nums[] = {4,5,1,3,1,1};
    int returnSize;
    int **ret_array = permuteUnique(nums, ARRAY_SIZE(nums), &returnSize);
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