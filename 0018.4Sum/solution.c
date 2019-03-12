#include <stdio.h>
#include <stdlib.h>

int compare_func(const void *num1, const void *num2) {
    if (*(int *)num1 == *(int *)num2)
        return 0;
    else if (*(int *)num1 < *(int *)num2)
        return -1;
    else
        return 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    int **ret_nums = NULL;
    *returnSize = 0;
    if (numsSize < 4)
        return NULL;
    qsort(nums, numsSize, sizeof(nums[0]), compare_func);
    for (int i = 0; i < numsSize-3; i++) {
        if (i != 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < numsSize-2; j++) {
            if (j != i+1 && nums[j] == nums[j-1]) continue;
#if 1 // O(n^2)
            if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
            if (nums[i] + nums[j] + nums[numsSize-2] + nums[numsSize-1] < target) continue;
            int left = j+1;
            int right = numsSize - 1;
            int tmp_sum;
            while (left < right) {
                tmp_sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (tmp_sum < target) {
                    left++;
                } else if (tmp_sum > target) {
                    right--;
                } else {
                    (*returnSize)++;
                    ret_nums = realloc(ret_nums, (*returnSize)*sizeof(int *));
                    if (ret_nums == NULL)
                        return NULL;
                    ret_nums[*returnSize-1] = malloc(sizeof(int) * 4);
                    if (ret_nums[*returnSize-1] == NULL)
                        return NULL;
                    ret_nums[*returnSize-1][0] = nums[i];
                    ret_nums[*returnSize-1][1] = nums[j];
                    ret_nums[*returnSize-1][2] = nums[left];
                    ret_nums[*returnSize-1][3] = nums[right];
                    do {left++;} while(nums[left] == nums[left-1] && left < right);
                    do {right--;} while(nums[right] == nums[right+1] && left < right);
                }
            }
#else  // Brute Force O(n^4)
            for (int k = j+1; k < numsSize; k++) {
                if (k != j+1 && nums[k] == nums[k-1]) continue;
                for (int l = k+1; l < numsSize; l++) {
                    if (l != k+1 && nums[l] == nums[l-1]) continue;
                    if (target == nums[i] + nums[j] + nums[k] + nums[l]) {
                        (*returnSize)++;
                        ret_nums = realloc(ret_nums, (*returnSize)*sizeof(int *));
                        if (ret_nums == NULL)
                            return NULL;
                        ret_nums[*returnSize-1] = malloc(sizeof(int) * 4);
                        if (ret_nums[*returnSize-1] == NULL)
                            return NULL;
                        ret_nums[*returnSize-1][0] = nums[i];
                        ret_nums[*returnSize-1][1] = nums[j];
                        ret_nums[*returnSize-1][2] = nums[k];
                        ret_nums[*returnSize-1][3] = nums[l];
                    }
                }
            }
#endif
        }
    }
    return ret_nums;
}

int main() {
    //int nums[] = {1, 0, -1, 0, -2, 2};
    //int target = 0;
    //int nums[] = {-1,-5,-5,-3,2,5,0,4};
    //int target = -7;
    int nums[] = {-1,0,1,2,-1,-4};
    int target = -1;
    int returnSize;
    int **ret_nums = fourSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d %d %d %d\n", ret_nums[i][0], ret_nums[i][1], ret_nums[i][2], ret_nums[i][3]);
        free(ret_nums[i]);
    }
    free(ret_nums);
    return 0;
}