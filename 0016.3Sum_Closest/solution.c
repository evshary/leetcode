#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "../C_library/library.h"

int compare_func(const void *num1, const void *num2) {
    if (*(int *)num1 > *(int *)num2)
        return 1;
    else if(*(int *)num1 < *(int *)num2)
        return -1;
    else
        return 0;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int closest_sum = INT_MAX;
    qsort(nums, numsSize, sizeof(int), compare_func);
    int tmp_sum;
    int left_idx, right_idx;
    if (numsSize < 3)
        return 0;
    for (int i = 0; i < numsSize-2; i++) {
        if (i != 0 && nums[i] == nums[i-1])
            continue;
        left_idx = i+1;
        right_idx = numsSize-1;
        do {
            tmp_sum = nums[i]+nums[left_idx]+nums[right_idx];
            if (closest_sum == INT_MAX || abs(target-tmp_sum) < abs(target-closest_sum)) {
                closest_sum = tmp_sum;
            }
            if (target > tmp_sum) {
                do {left_idx++;}while(left_idx < right_idx && nums[left_idx]==nums[left_idx-1]);
            } else if(target < tmp_sum) {
                do {right_idx--;}while(left_idx < right_idx && nums[right_idx]==nums[right_idx+1]);
            } else {
                return tmp_sum;
            }
        } while(left_idx<right_idx);
    }
    return closest_sum;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int target = 2;
    printf("threeSumClosest: %d\n", threeSumClosest(nums, ARRAY_SIZE(nums), target));
    return 0;
}