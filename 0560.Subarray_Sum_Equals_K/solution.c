#include <stdio.h>

#if 1 // without using too much memory, use the input array
int subarraySum(int* nums, int numsSize, int k){
    int count = 0;
    if (nums[0] == k) count++;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i-1];
        if (nums[i] == k) count++;
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[j]-nums[i] == k) count++;
        }
    }
    return count;
}
#else
int subarraySum(int* nums, int numsSize, int k){
    int dp[numsSize+1];
    int count = 0;
    dp[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        dp[i+1] = dp[i] + nums[i];
        if (dp[i+1] == k) count++;
    }
    for (int i = 1; i < numsSize; i++) {
        for (int j = i+1; j < numsSize+1; j++) {
            dp[j] -= dp[i];
            if (dp[j] == k) count++;
        }
    }
    return count;
}
#endif

int main() {
    int nums[] = {1,1,1};
    int k = 2;
    printf("result=%d\n", subarraySum(nums, sizeof(nums)/sizeof(int), k));
    return 0;
}