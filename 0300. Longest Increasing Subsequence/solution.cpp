#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tmp_array;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (tmp_array.size() == 0) {
                tmp_array.push_back(*it);
                continue;
            }
            if (*it > tmp_array.back())
                tmp_array.push_back(*it);
            else {
                int i;
                for (i = 0; i < tmp_array.size(); i++) {
                    if (*it <= tmp_array[i])
                        break;
                }
                if (i == tmp_array.size())
                    tmp_array[i-1] = *it;
                else
                    tmp_array[i] = *it;
            }
#if 0
            for (int i = 0; i < tmp_array.size(); i++) {
                cout << tmp_array[i] << " ";
            }
            cout << endl;
#endif
        }
        return tmp_array.size();
    }
};

int main() {
#if 0
    vector<int> nums{10,9,2,5,3,7,101,18};
#elif 0
    vector<int> nums{0};
#elif 1
    vector<int> nums{10,9,2,5,3,4};
#endif
    Solution solution;
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}