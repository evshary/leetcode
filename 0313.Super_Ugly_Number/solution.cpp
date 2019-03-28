#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ret_array(n);
        int primes_num = primes.size();
        vector<int> pos(primes_num, 0);
        int temp_min;
        ret_array[0] = 1;
        for (int i = 1; i < n; i++) {
            temp_min = INT_MAX;
            for (int j = 0; j < primes_num; j++) {
                temp_min = min(temp_min, ret_array[pos[j]] * primes[j]);
            }
            for (int j = 0; j < primes_num; j++) {
                if (temp_min == ret_array[pos[j]] * primes[j])
                    pos[j]++;
            }
            ret_array[i] = temp_min;
        }
        return ret_array[n-1];
    }
};

int main() {
    int n = 12;
    vector<int> primes{2,7,13,19};
    Solution solution;
    cout << solution.nthSuperUglyNumber(n, primes);
    return 0;
}