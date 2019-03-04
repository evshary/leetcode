#include <stdio.h>

#define max(x,y) ((x)>(y))?(x):(y)
int maxSubArray_r(int *nums, int left, int right) {
    if (left >= right) {
        //printf("nums[%d]=%d right=%d\r\n", left, nums[left], right);
        return nums[left];
    } else {
        int middle = left + (right-left)/2;
        //printf("left=%d right=%d middle=%d\r\n", left, right, middle);
        int left_max = maxSubArray_r(nums, left, middle-1);
        int right_max = maxSubArray_r(nums, middle+1, right);
        int sum_left = 0, sum_right = 0;
        for (int i = middle-1, sum = 0; i >= left; i--) {
            sum += nums[i];
            sum_left = max(sum_left, sum);
        }
        for (int i = middle+1, sum = 0; i <= right; i++) {
            sum += nums[i];
            sum_right = max(sum_right, sum);
        }
        //printf("left_max=%d right_max=%d sum_left=%d sum_right=%d\r\n", left_max, right_max, sum_left, sum_right);
        return max(max(left_max, right_max), sum_left+sum_right+nums[middle]);
    }
}

int maxSubArray(int* nums, int numsSize) {
    return maxSubArray_r(nums, 0, numsSize-1);
}

/* Using Divide & Conquer */
int main() {
    int input[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("maxSubArray=%d\r\n", maxSubArray(input, sizeof(input)/sizeof(input[0])));
    return 0;
}