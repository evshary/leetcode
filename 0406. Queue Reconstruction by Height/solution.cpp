#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare_func(pair<int,int> num1, pair<int,int> num2) {
    if (num1.first < num2.first)
        return true;
    else if (num1.first > num2.first)
        return false;
    else {
        if (num1.second > num2.second)
            return true;
        else
            return false;
    }
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ret_nums;
        sort(people.begin(),people.end(), compare_func);
        for (vector<pair<int,int>>::reverse_iterator it = people.rbegin(); it != people.rend(); ++it) {
            ret_nums.insert(ret_nums.begin() + it->second, *it);
        }
        return ret_nums;
    }
};

int main() {
    Solution solution;
    //[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    vector<int> num1{7,4,7,5,6,5};
    vector<int> num2{0,4,1,0,1,2};
    vector<pair<int, int>> pair_nums;
    for (int i = 0; i < num1.size(); i++) {
        pair_nums.push_back(make_pair(num1[i],num2[i]));
    }
    vector<pair<int, int>> ret_nums = solution.reconstructQueue(pair_nums);
    for (auto it = ret_nums.begin(); it != ret_nums.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}