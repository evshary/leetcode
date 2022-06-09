#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if 1 // better way
int findTotalSumWays(int* nums, int numsSize, int sum) {
    int dp[sum+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = sum; j >= nums[i]; j--) {
            dp[j] += dp[j-nums[i]];
        }
    }
    return dp[sum];
}

int findTargetSumWays(int* nums, int numsSize, int S){
    // sum(positive) - sum(negitive) = S
    // sum(P) - sum(N) + sum(P) + sum(N) = S + sum(P) + sum(N)
    // 2sum(P) = S + sum(nums)
    // sum(P) = (S + sum(nums)) / 2
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    // S > sum means no possibility to reach S.
    // That S + sum is odd means it's impossible to find sum(P)
    if (S > sum || (S + sum) % 2 == 1) return 0;
    // Do dyanmic table
    return findTotalSumWays(nums, numsSize, (S+sum)/2);
}
#else
int findTargetSumWays_r(int* nums, int numsSize, int sum, int target) {
    if (sum == target) return 1;
    if (numsSize == 0 || sum < target) return 0;
    return findTargetSumWays_r(nums+1, numsSize-1, sum-(2*nums[0]), target) + findTargetSumWays_r(nums+1, numsSize-1, sum, target);
}

int compare_func(const void *l, const void *r) {
    return (*(int *)l - *(int *)r);
}

int findTargetSumWays(int* nums, int numsSize, int S){
    if (numsSize == 0) {
        if (S == 0) return 1;
        else return 0;
    }
    qsort(nums, numsSize, sizeof(int), compare_func);
    int mul_num = 0;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (nums[i] == 0) mul_num++;
    }
    // ignore the zero and find all the combinations
    int ret = findTargetSumWays_r(nums+mul_num, numsSize-mul_num, sum, S);
    for (int i = mul_num; i > 0; i--)
        ret *= 2;
    return ret;
}
#endif

int main() {
    int nums[] = {3,2,1,0,2};
    int S = 2;
    printf("target: %d\n", findTargetSumWays(nums, sizeof(nums)/sizeof(int), S));
    return 0;
}