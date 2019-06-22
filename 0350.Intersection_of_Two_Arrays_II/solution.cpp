#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash_table;
        vector<int> result;
        // transform nums1 to hash table
        for (auto num : nums1) {
            if (hash_table.find(num) == hash_table.end()) {
                hash_table[num] = 1;
            } else {
                hash_table[num]++;
            }
        }
        // compare with nums2
        for (auto num : nums2) {
            if (hash_table.find(num) != hash_table.end() && hash_table[num] != 0) {
                hash_table[num]--;
                result.push_back(num);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1{1,2,2,1};
    vector<int> nums2{2,2};
    Solution s;
    cout << "result: ";
    for (auto num : s.intersect(nums1, nums2)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}