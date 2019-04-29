#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char cur_operator = '+';
        int operand = 0;
        s = s + "+";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            if (s[i] >= '0' && s[i] <= '9') {
                operand = operand * 10 - '0'+ s[i];
            } else {
                if (cur_operator == '-') {
                    operand *= -1;
                } else if (cur_operator == '*') {
                    operand = nums.top() * operand;
                    nums.pop();
                } else if (cur_operator == '/') {
                    operand = nums.top() / operand;
                    nums.pop();
                }
                nums.push(operand);
                operand = 0;
                cur_operator = s[i];
            }
        }
        int result = 0;
        while(!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};

int main() {
    vector<string> problems{"3+2*2",
                            " 3/2 ",
                            " 3+5 / 2 "};
    Solution solution;
    for (auto s : problems)
        cout << s << ": " << solution.calculate(s) << endl;
    return 0;
}