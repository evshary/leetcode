#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#if 1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        int tmp = 1;
        for (int i = 0; i < size; i++) {
            result[i] = result[i] * tmp;
            tmp *= nums[i];
        }
        tmp = 1;
        for (int i = size-1; i >= 0; i--) {
            result[i] = result[i] * tmp;
            tmp *= nums[i];
        }
        return result;
    }
};
#else // wrong!!!!! I misunderstand the problems
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int,int> hash;
        vector<int> result;
        int idx = 1;
        int max_idx = 1 << nums.size();
        for (auto num : nums) {
            hash[num] = 1;
        }
        while (idx < max_idx) {
            int tmp = 1;
            for (int tmp_idx = 0; tmp_idx < nums.size(); tmp_idx++) {
                if ((1 << tmp_idx) & idx)
                    tmp *= nums[tmp_idx];
            }
            if (hash.find(tmp) == hash.end())
                hash[tmp] = 2;
            idx++;
        }
        for (auto element : hash) {
            if (element.second == 2)
                result.push_back(element.first);
        }
        sort(result.rbegin(), result.rend());
        return result;
    }
};
#endif

int main() {
    vector<vector<int>> problems{{1,2,3,4}};
    Solution solution;
    vector<int> result;
    for (auto p : problems) {
        cout << "[";
        for (auto num : p) cout << num << " ";
        result = solution.productExceptSelf(p);
        cout << "]: [";
        for (auto num : result) cout << num << " ";
        cout << "]" << endl;
    }
    return 0;
}