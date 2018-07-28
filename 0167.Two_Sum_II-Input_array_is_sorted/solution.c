/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i, j;
    int *ret_array;

    *returnSize = 2;
    ret_array = (int *)malloc(sizeof(int) * *(returnSize));

    for (i = 0; i < numbersSize-1; i++)
    {
        for (j = numbersSize-1; j > i; j--)
        {
            if ( *(numbers+i)+*(numbers+j) <= target)
                break;
        }
        if ( *(numbers+i)+*(numbers+j) == target)
        {
            *ret_array = i+1;
            *(ret_array+1) = j+1;
            break;
        }
    }

    return ret_array;
}

int main()
{
    int nums[] = {2,7,11,15};
    int *ret_array;
    int returnSize;

    ret_array = twoSum(nums, sizeof(nums)/sizeof(int), 9, &returnSize);
    printf("result = %d %d\n", ret_array[0], ret_array[1]);
    free(ret_array);

    return 0;
}