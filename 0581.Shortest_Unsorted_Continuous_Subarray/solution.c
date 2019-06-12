#include <stdio.h>

#if 1 // one pass solution (combine two array)
int findUnsortedSubarray(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1) return 0;
    int left_ptr = 0, right_ptr = numsSize - 1;
    for (int i = 0, j = numsSize-1; i < numsSize; i++, j--) {
        while (left_ptr != 0 && nums[i] < nums[left_ptr-1])
            left_ptr--;
        if (i == left_ptr) left_ptr++;
        while (right_ptr != numsSize-1 && nums[j] > nums[right_ptr+1])
            right_ptr++;
        if (j == right_ptr) right_ptr--;
    }
    if (right_ptr <= left_ptr) return 0;
    return right_ptr-left_ptr+1;
}
#else
int findUnsortedSubarray(int* nums, int numsSize){
    if (numsSize == 0 || numsSize == 1) return 0;
    int left_ptr = 0, right_ptr = numsSize - 1;
    // from small to big
    for (int i = 0; i < numsSize; i++) {
        while (left_ptr != 0 && nums[i] < nums[left_ptr-1])
            left_ptr--;
        if (i == left_ptr) left_ptr++;
    }
    // from big to small
    for (int i = numsSize-1; i >= 0; i--) {
        while (right_ptr != numsSize-1 && nums[i] > nums[right_ptr+1])
            right_ptr++;
        if (i == right_ptr) right_ptr--;
    }
    if (right_ptr <= left_ptr) return 0;
    return right_ptr-left_ptr+1;
}
#endif

int main() {
    //int nums[] = {2,6,4,8,10,9,15};
    //int nums[] = {1,2,5,4,9,3,10,11};
    //int nums[] = {1,3,10,12};
    //int nums[] = {3,1,10,12};
    //int nums[] = {1,3,12,10};
    //int nums[] = {3,12,1,10};
    int nums[] = {1,10,3,12};
    int nums_size = sizeof(nums)/sizeof(nums[0]);
    printf("result=%d\n", findUnsortedSubarray(nums, nums_size));
    return 0;
}