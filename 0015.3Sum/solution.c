/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *arg1, const void *arg2)
{
    return (*((int *)arg1) - * ((int *)arg2));
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int all_combin_num = 0;
    int **sol;
    int *sorted_nums;
    int sol_num = 0;
    int left, right, sum;

    all_combin_num = (numsSize * (numsSize - 1) * (numsSize - 2)) / 6;
    sol = (int **)malloc(sizeof(int *) * all_combin_num);

    // Do sorting
    sorted_nums = (int *)malloc(sizeof(int) * numsSize);
    memcpy(sorted_nums, nums, (sizeof(int) * numsSize));
    qsort((void *)sorted_nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i++)
    {
        if (i > 0 && sorted_nums[i - 1] == sorted_nums[i])
            continue;
        left = i + 1;
        right = numsSize - 1;
        while (left < right)
        {
            sum = sorted_nums[i] + sorted_nums[left] + sorted_nums[right];
            if (sum > 0)
            {
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                sol[sol_num] = (int *)malloc(sizeof(int) * 3);
                sol[sol_num][0] = sorted_nums[i];
                sol[sol_num][1] = sorted_nums[left];
                sol[sol_num][2] = sorted_nums[right];
                sol_num++;
                do
                {
                    left++;
                }
                while (sorted_nums[left] == sorted_nums[left - 1] && left < right);
                do
                {
                    right--;
                }
                while (sorted_nums[right] == sorted_nums[right + 1] && left < right);
            }
        }
    }

    free(sorted_nums);
    *returnSize = sol_num;
    return sol;
}

int main()
{
    int nums[] = { -1, 0, 1, 2, -1, -4};
    int returnSize;
    int **answer;

    answer = threeSum(nums, sizeof(nums) / sizeof(int), &returnSize);
    printf("returnSize: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("[%d, %d, %d]\r\n", answer[i][0], answer[i][1], answer[i][2]);

    // Free resource
    for (int i = 0; i < returnSize; i++)
        free(answer[i]);
    free(answer);

    return 0;
}