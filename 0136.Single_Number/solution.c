#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int ret_val = 0;
    for (int i = 0; i < numsSize; i++)
        ret_val ^= nums[i];
    return ret_val;
}

int main() {
    int nums[] = {4,1,2,1,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    printf("singleNumber=%d\n", singleNumber(nums, numsSize));
    return 0;
}