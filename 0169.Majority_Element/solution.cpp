#include <iostream>
#include <vector>
#include <map>
using namespace std;

#if 1 /* Use Boyer-Moore Voting Algorithm */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target;
        int count = 0;
        for (auto num : nums) {
            if (count == 0) {
                target = num;
                count++;
            } else if (target == num)
                count++;
            else
                count--;
        }
        return target;
    }
};
#else
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> hash;
        for (auto num : nums) {
            if (hash.find(num) == hash.end())
                hash[num] = 1;
            else
                hash[num]++;
            if (hash[num] * 2 > nums.size())
                return num;
        }
        return 0;
    }
};
#endif

int main() {
    Solution solution;
    vector<vector<int>> problems{{3,2,3}, {2,2,1,1,1,2,2}};
    for (auto p : problems) {
        cout << "P[";
        for (auto num : p) cout << num << " ";
        cout << "]: ";
        cout << solution.majorityElement(p) << endl;;
    }
    return 0;
}