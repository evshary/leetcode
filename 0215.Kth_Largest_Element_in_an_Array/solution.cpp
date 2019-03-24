#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#if 1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums[k-1];
    }
};
#else
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pqueue;
        for (int i = 0; i < nums.size(); i++) {
            pqueue.push(nums[i]);
            if (pqueue.size() > k)
                pqueue.pop();
        }
        return pqueue.top();
    }
};
#endif


int main() {
    vector<int> nums{ 3, 2, 1, 5, 6, 4 };
    int k = 2;
    Solution solution;
    cout << "findKthLargest: " << solution.findKthLargest(nums, k) << endl;
    return 0;
}