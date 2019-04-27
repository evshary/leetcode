#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
#if 0 // spending too much time, time: O(nlogn), space: O(1)
        vector<int> array(nums.size(), 0);
        int min_len = 0, tmp_min_len;
        for (int i = nums.size()-1; i >= 0; i--) {
            for (int j = nums.size()-1; j >= i; j--) {
                array[j] += nums[i];
                if (array[j] >= s) {
                    tmp_min_len = j - i + 1;
                    if (min_len == 0 || min_len > tmp_min_len)
                        min_len = tmp_min_len;
                }
            }
        }
        return min_len;
#else
        int start = 0, end = 0;
        int sum = 0;
        int min_len = 0;
        while(end < nums.size()) {
            sum += nums[end++];
            while(start+1 < end && sum - nums[start] >= s) {
                sum -= nums[start];
                start++;
            }
            if (sum >= s && (min_len == 0 || end - start < min_len)) {
                min_len = end - start;
            }
        }
        return min_len;
#endif
    }
};

int main() {
    int s = 7;
    vector<int> nums{2,3,1,2,4,3};
    Solution solution;
    cout << "return: " << solution.minSubArrayLen(s, nums) << endl;
    return 0;
}