#include <stdio.h>

#if 1  // I don't need to move the firstZeroIdx first.
void moveZeroes(int* nums, int numsSize){
    int firstZeroIdx = 0, tmp;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            tmp = nums[firstZeroIdx];
            nums[firstZeroIdx] = nums[i];
            nums[i] = tmp;
            firstZeroIdx++;
        }
    }
}
#else
void moveZeroes(int* nums, int numsSize){
    int firstZeroIdx = 0;
    int tmp;
    while(firstZeroIdx < numsSize && nums[firstZeroIdx] != 0) firstZeroIdx++;
    for (int i = firstZeroIdx; i < numsSize; i++) {
        if (nums[i] != 0) {
            tmp = nums[firstZeroIdx];
            nums[firstZeroIdx] = nums[i];
            nums[i] = tmp;
        }
        while(nums[firstZeroIdx] != 0) firstZeroIdx++;
    }
}
#endif

int main() {
    int nums[] = {0,1,0,3,12};
    //int nums[] = {6,1,8,3,12};
    //int nums[] = {6,0,0,0,3,12,1,2,43};
    //int nums[] = {};
    //int nums[] = {0};
    int num_size = sizeof(nums)/sizeof(int);
    moveZeroes(nums, num_size);
    for (int i = 0; i < num_size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}