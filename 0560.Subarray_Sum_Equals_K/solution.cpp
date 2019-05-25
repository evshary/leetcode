#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * sum[i:j] = sum[0:j] - sum[0:i-1]
 *     k    =   sum    -  htable-key
 * sum[0:i-1] = sum[0:j] - sum[i:j]
 * htable-key =   sum    -   k
 * 
 * If we have 0:i-1 that equals to sum-k, then we can get to k.
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> htable;
        htable[0] = 1;
        int sum = 0;
        int res = 0;
        for (auto num : nums) {
            sum += num;
            res += htable[sum-k];
            htable[sum] += 1;
        }
        return res;
    }
};

int main() {
    vector<int> nums{1,1,1};
    int k = 2;
    Solution s;
    cout << s.subarraySum(nums, k) << endl;;
    return 0;
}