#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int start = 0, end = 2;
        int arith_num = 0;
        while (end < A.size()) {
            /* Expand sliding window */
            while (A[end] - A[end-1] == A[end-1] - A[end-2]) {
                end++;
                if (end == A.size()) break;
            }
            /* count the arithmetic array number */
            start += 2;
            int tmp = 1;
            while (start < end) {
                arith_num += tmp;
                tmp++;
                start++;
            }
            start -= 1; // we should start from the last element
            end = start+2;
        }
        return arith_num;
    }
};

int main() {
    vector<int> A{1,2,3,4,7,10,13};
    Solution solution;
    cout << solution.numberOfArithmeticSlices(A) << endl;
    return 0;
}