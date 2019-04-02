#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string str = "";
        char ch[8] = {0};
        int i;
        for (i = 7; i >= 0; i--) {
            ch[i] = (num & 0xf);
            if (ch[i] >= 0 && ch[i] <= 9)
                ch[i] += '0';
            else if (ch[i] >= 0xa && ch[i] <= 0xf)
                ch[i] += 'a' - 0xa;
            num >>= 4;
        }
        i = 0;
        while(i < 8 && ch[i] == '0') i++;
        for (; i < 8; i++) {
            str.push_back(ch[i]);
        }
        if (str.empty())
            str.push_back('0');
        return str;
    }
};

int main() {
    Solution solution;
    vector<int> test_cases{26, -1, 5, 0, 100};
    for (auto test_case : test_cases) {
        cout << test_case << ":" << solution.toHex(test_case) << endl;
    }
    return 0;
}