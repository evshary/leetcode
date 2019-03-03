#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int nums_start[numsSize], nums_step[numsSize];
    char **summary;
    *returnSize = -1;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums_start[*returnSize] + nums_step[*returnSize] + 1 != nums[i]) {
            (*returnSize)++;
            nums_start[*returnSize] = nums[i];
            nums_step[*returnSize] = 0;
        } else {
            nums_step[*returnSize]++;
        }
    }
    (*returnSize)++;
    summary = malloc(*returnSize * sizeof(char *));
    for (int i = 0; i < *returnSize; i++) {
        summary[i] = malloc(30);
        if (nums_step[i] != 0)
            sprintf(summary[i], "%d->%d", nums_start[i], nums_start[i]+nums_step[i]);
        else
            sprintf(summary[i], "%d", nums_start[i]);
    }
    return summary;
}

int main()
{
    int nums[] = {0,1,2,4,5,7};
    int returnSize;
    char **summary = summaryRanges(nums, sizeof(nums)/sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("Range=%s\n", summary[i]);
        free(summary[i]);
    }
    free(summary);
    return 0;
}