#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../C_library/library.h"

int **ret_array;
int *col_array;
int arr_size;
int max_arr_size;

void subsets_r(int *nums, int numsSize, int array_idx, int *tmp_stack, int cur_stack_size) {
    if (numsSize == array_idx) {
        if (arr_size == max_arr_size) {
            max_arr_size *= 2;
            col_array = realloc(col_array, sizeof(int) * max_arr_size);
            ret_array = realloc(ret_array, sizeof(int *) * max_arr_size);
        }
        col_array[arr_size] = cur_stack_size;
        ret_array[arr_size] = malloc(sizeof(int) * cur_stack_size);
        memcpy(ret_array[arr_size], tmp_stack, sizeof(int) * cur_stack_size);
        arr_size++;
        return;
    }
    // don't select current value
    subsets_r(nums, numsSize, array_idx+1, tmp_stack, cur_stack_size);
    // select current value
    tmp_stack[cur_stack_size++] = nums[array_idx];
    subsets_r(nums, numsSize, array_idx+1, tmp_stack, cur_stack_size);
}

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    max_arr_size = 5;
    arr_size = 0;
    ret_array = malloc(sizeof(int *) * max_arr_size);
    col_array = malloc(sizeof(int) * max_arr_size);
    if (numsSize == 0) {
        ret_array[0] = NULL;
        *returnSize = 1;
        return ret_array;
    }
    int tmp_stack[numsSize];
    subsets_r(nums, numsSize, 0, tmp_stack, 0);
    *returnSize = arr_size;
    *columnSizes = col_array;
    return ret_array;
}

int main() {
    int nums[] = {1,2,3};
    int returnSize;
    int *columnSizes;
    int **ret_array = subsets(nums, ARRAY_SIZE(nums), &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", ret_array[i][j]);
        }
        printf("\n");
        free(ret_array[i]);
    }
    free(ret_array);
    return 0;
}