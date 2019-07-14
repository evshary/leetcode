#include <iostream>
#include <vector>
using namespace std;

#if 1 // Solve the problem with O(N)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v(gas.size(), 0);
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            v[i] = gas[i] - cost[i];
            sum += v[i];
        }
        if (sum < 0) return -1;
        /* Now we know there must be a solution here. */
        int start_idx = 0;
        sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
            if (sum < 0) {
                sum = 0;
                start_idx = i+1;
            }
        }
        return start_idx;
    }
};
#else // O(N^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v(gas.size(), 0);
        int sum = 0;
        for (int i = 0; i < gas.size(); i++) {
            v[i] = gas[i] - cost[i];
            sum += v[i];
        }
        if (sum < 0) return -1;
        for (int i = 0; i < v.size(); i++) {
            int cur_num = 0;
            bool found_ans = true;
            for (int j = 0; j < v.size(); j++) {
                cur_num += v[(i+j)%v.size()];
                if (cur_num < 0) {
                    found_ans = false;
                    break;
                }
            }
            if (found_ans) return i;
        }
        return -1;
    }
};
#endif

int main() {
    Solution s;
#if 0
    vector<int> gas{1,2,3,4,5};
    vector<int> cost{3,4,5,1,2};
#elif 0
    vector<int> gas{2,3,4};
    vector<int> cost{3,4,3};
#elif 1
    vector<int> gas{5,8,2,8};
    vector<int> cost{6,5,6,6};
#endif
    cout << "result: " << s.canCompleteCircuit(gas, cost) << endl;;
    return 0;
}