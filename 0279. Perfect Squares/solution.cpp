#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void numSquares_r(int n, int depth) {
        if (n == 0) {
            min_num = min(depth, min_num);
            return;
        } else if (n < 0 || depth >= min_num)
            return;
        for (int i = square_db.size()-1; i >= 0; i--) {
            numSquares_r(n-square_db[i], depth+1);
        }
    }
    int numSquares(int n) {
        square_db.clear();
        min_num = INT_MAX;
        int square_num = 1;
        while(square_num * square_num <= n) {
            square_db.push_back(square_num * square_num);
            square_num++;
        }
        numSquares_r(n, 0);
        return min_num;
    }
private:
    vector<int> square_db;
    int min_num;
};

int main() {
    Solution solution;
    int n = 12;
    cout << "numSquares: " << solution.numSquares(n) << endl;
    return 0;
}