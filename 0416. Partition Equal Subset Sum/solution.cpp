#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#if 1
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        if (nums.size() < 2) return false;
        for (auto num: nums)
            total_sum += num;
        if (total_sum % 2) return false;
        total_sum /= 2;
        vector<bool> dp(total_sum+1, false);
        dp[0] = true;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = total_sum; j > 0; j--) {
                if (j >= nums[i-1])
                    dp[j] = dp[j] || dp[j - nums[i-1]];
            }
        }
        return dp[total_sum];
    }
#else
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        if (nums.size() < 2) return false;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            total_sum += *it;
        }
        if (total_sum % 2) return false;
        total_sum /= 2;
        vector<vector<bool>> dp(nums.size()+1, vector<bool>(total_sum+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= nums.size(); i++)
            dp[i][0] = true;
        for (int j = 1; j <= total_sum; j++)
            dp[0][j] = false;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= total_sum; j++) {
                if (j >= nums[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[nums.size()][total_sum];
    }
#endif
};

int main() {
    Solution solution;
#if 0
    vector<int> nums{1,5,11,5};
#elif 1
    vector<int> nums{1,2,5};
#elif 0
    vector<int> nums{1,2,3,4,5,6,7};
#endif
    cout << solution.canPartition(nums) << endl;
    return 0;
}