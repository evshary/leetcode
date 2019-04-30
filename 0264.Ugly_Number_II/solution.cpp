#include <iostream>
#include <vector>
#include <map>
using namespace std;

#if 1
#define INSERT(N) \
            do { \
                if (INT_MAX/N < nums[valid_n-1]) break; \
                tmp_num = nums[valid_n-1] * N; \
                while(tmp_i < nums.size() && nums[tmp_i] <= tmp_num) tmp_i++; \
                if (tmp_num != nums[tmp_i-1]) \
                    nums.insert(nums.begin() + tmp_i, tmp_num); \
            } while(0);

class Solution {
public:
    int nthUglyNumber(int n) {
        if (nums.empty()) {
            nums.push_back(1);
            valid_n = 1;
        }
        int tmp_i, tmp_num;
        while (valid_n < n) {
            tmp_i = valid_n;
            INSERT(2);
            INSERT(3);
            INSERT(5);
            valid_n++;
        }
        return nums[n-1];
    }
private:
    vector<int> nums;
    int valid_n;
};
#else /* Too slow */
#define CHECK_FACTOR(N) \
    while(tmp_value > max_valid_value && tmp_value % N == 0) { \
        tmp_value /= N; \
    }

class Solution {
public:
    int nthUglyNumber(int n) {
        int cur_n = 1;
        int n_value = 1;
        int max_valid_value = 1;
        int tmp_value;
        map<int,bool> htable;
        while(cur_n != n) {
            n_value++;
            tmp_value = n_value;
            CHECK_FACTOR(2);
            CHECK_FACTOR(3);
            CHECK_FACTOR(5);
            if (htable.find(tmp_value) != htable.end() || tmp_value == 1) {
                max_valid_value = n_value;
                htable[n_value] = true;
                cur_n++;
            }
        }
        return n_value;
    }
};
#endif

int main() {
    Solution solution;
    vector<int> problems{1,2,3,4,5,10,20,60,1500,1690};
    for (auto num : problems)
        cout << num << " Ugly Number: "<< solution.nthUglyNumber(num) << endl;
    return 0;
}