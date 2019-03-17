#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../C_library/library.h"

static int **ret_val;
static int max_row_size;
static int row_size;
static int *col_size;
static int *array;
static int max_array_size;
static int array_size;

void addCombination(int *array, int array_size) {
    if (row_size == max_row_size) {
        max_row_size *= 2;
        ret_val = realloc(ret_val, max_row_size * sizeof(int *));
        col_size = realloc(col_size, max_row_size * sizeof(int *));
    }
    ret_val[row_size] = malloc(sizeof(int)*array_size);
    memcpy(ret_val[row_size], array, sizeof(int)*array_size);
    col_size[row_size] = array_size;
    row_size++;
}

void combinationSum_r(int *candidates, int candidatesSize, int start, int target) {
    if (target == 0) {
        addCombination(array, array_size);
        return;
    } else if (target < 0) {
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        array[array_size] = candidates[i];
        array_size++;
        if (array_size == max_array_size) {
            max_array_size *= 2;
            array = realloc(array, max_array_size * sizeof(int));
        }
        combinationSum_r(candidates, candidatesSize, i, target - candidates[i]);
        array_size--;
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    max_row_size = 5;
    row_size = 0;
    ret_val = malloc(max_row_size * sizeof(int *));
    col_size = malloc(max_row_size * sizeof(int));
    max_array_size = max_row_size;
    array_size = 0;
    array = malloc(max_array_size * sizeof(int));
    combinationSum_r(candidates, candidatesSize, 0, target);
    free(array);
    *returnSize = row_size;
    *columnSizes = col_size;
    return ret_val;
}

int main() {
#if 0
    int candidates[] = {2,3,6,7};
    int target = 7;
#elif 1
    int candidates[] = {2,3,5};
    int target = 8;
#else
    int candidates[] = {7,3};
    int target = 17;
#endif
    int *columnSizes;
    int returnSize;
    int **ret_val = combinationSum(candidates, ARRAY_SIZE(candidates), target, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", ret_val[i][j]);
        }
        printf("\n");
        free(ret_val[i]);
    }
    free(ret_val);
    free(columnSizes);
    return 0;
}