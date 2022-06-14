#include <stdio.h>

#define max(x,y) ((x)>(y))?(x):(y)
int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }
    return maxSum;
}

int main() {
    int input[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("maxSubArray=%d\r\n", maxSubArray(input, sizeof(input)/sizeof(input[0])));
    return 0;
}