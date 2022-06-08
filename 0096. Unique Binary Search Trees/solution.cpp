#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution() {
        d_table.clear();
        d_table.push_back(1); // 0
        d_table.push_back(1); // 1
    }
    int numTrees(int n) {
        if (n < 0) return 0;
        while (n >= d_table.size()) {
            int cur_n = d_table.size();
            int s, b, sum = 0;
            for (s = cur_n-1, b = 0; b < s; s--, b++){
                sum += d_table[s] * d_table[b];
            }
            if (s == b) sum = sum + d_table[s]*d_table[b] + sum;
            else sum += sum;
            d_table.push_back(sum);
        }
        return d_table[n];
    }
private:
    vector<int> d_table;
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;;
    return 0;
}