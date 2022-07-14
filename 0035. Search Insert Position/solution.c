#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInsert(int* nums, int numsSize, int target) {
    int i;
    for (i = 0; i < numsSize; i++) {
        if (target <= nums[i])
            break;
    }
    return i;
}

int main()
{
    int nums[] = {1,3,5,6};
    int target = 7;
    
    printf("Insert position=%d\n", searchInsert(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}