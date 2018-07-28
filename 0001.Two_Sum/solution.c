/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int compare(const void *arg1, const void *arg2)
{
    return (*((int *)arg1) - * ((int *)arg2));
}

int* twoSum(int* nums, int numsSize, int target) {
    int i, j, k;
    int *ret_array = (int *)malloc(sizeof(int) * 2);
    int *sorted_nums;
    int ret_num = 0;

    // do sorting
    sorted_nums = (int *)malloc(sizeof(int) * numsSize);
    memcpy(sorted_nums, nums, (sizeof(int) * numsSize));
    qsort((void *)sorted_nums, numsSize, sizeof(int), compare);

    for (i = 0; i < numsSize-1; i++)
    {
        for (j = numsSize-1; j > i; j--)
        {
            if ( *(sorted_nums+i)+*(sorted_nums+j) <= target)
                break;
        }
        if ( *(sorted_nums+i)+*(sorted_nums+j) == target)
            break;
    }
    // Find the corresponding index of orgin array.
    for (k = 0; k < numsSize; k++)
    {
        if (nums[k] == sorted_nums[i] || nums[k] == sorted_nums[j])
        {
            *(ret_array+ret_num) = k;
            ret_num++;
            if (ret_num == 2)
                break;
        }
    }
    free(sorted_nums);
    return ret_array;
}

int main()
{
    int nums[] = {3,2,4};
    int *ret_array;
    
    ret_array = twoSum(nums, sizeof(nums)/sizeof(int), 6);
    printf("result = %d %d\n", ret_array[0], ret_array[1]);
    free(ret_array);

    return 0;
}