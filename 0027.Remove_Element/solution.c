#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int tmp;
    while (i < numsSize) {
        if (nums[i] == val) {
            if (nums[numsSize-1] == val) {
                numsSize--;
                continue;
            }
            tmp = nums[i];
            nums[i] = nums[numsSize-1];
            nums[numsSize-1] = tmp;
        }
        i++;
    }
    return numsSize;
}

int main()
{
    int i;
    int nums[] = {0,1,2,2,3,0,4,2};
    int arrlen = removeElement(nums, (sizeof(nums)/sizeof(int)), 2);
    for (i = 0; i < arrlen; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}