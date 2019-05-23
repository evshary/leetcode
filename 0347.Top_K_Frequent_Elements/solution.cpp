#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> l, pair<int,int> r) {
    return r.second < l.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> htable;
        for (auto num : nums) {
            if (htable.find(num) == htable.end()) {
                htable[num] = 1;
            } else {
                htable[num]++;
            }
        }
        vector<pair<int,int>> sort_result;
        for (auto i : htable) sort_result.push_back(i);
        sort(sort_result.begin(), sort_result.end(), comp);
        vector<int> ret;
        for (int i = 0; i < k; i++) ret.push_back(sort_result[i].first);
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1,5,5,5,1,1,2,2,3,3,3,3};
    int k = 2;
    vector<int> result = solution.topKFrequent(nums, k);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}