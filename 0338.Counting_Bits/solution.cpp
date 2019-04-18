#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(1, 0);
        int size = result.size();
        while(size < num+1) {
            result.reserve(size * 2);
            for (int i = 0; i < size; i++) {
                if (result.size() >= num+1)
                    break;
                result.push_back(result[i] + 1);
            }
            size = result.size();
        }
        return result;
    }
};

int main() {
    Solution solution;
    int num = 10;
    vector<int> result = solution.countBits(num);
    cout << "count bits: ";
    for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}