#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *num1, const void *num2) {
    if (*(int *)num1 > *(int *)num2)
        return 1;
    else if (*(int *)num1 < *(int *)num2)
        return -1;
    else
        return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1])
            return true;
    }
    return false;
}

int main() {
    int nums[] = {1,2,3,1};
    if (containsDuplicate(nums, sizeof(nums)/sizeof(nums[0])))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}