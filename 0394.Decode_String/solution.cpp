#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string str = "", tmp_str;
        int number = 0;
        stack<string> str_stack;
        stack<int> num_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (number == 0) {
                    str_stack.push(str);
                    str = "";
                }
                number = number * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                num_stack.push(number);
                number = 0;
            } else if (s[i] == ']') {
                tmp_str = str_stack.top();
                str_stack.pop();
                for (int j = 0; j < num_stack.top(); j++) {
                    tmp_str += str;
                }
                str = tmp_str;
                num_stack.pop();
            } else {
                str += s[i];
            }
        }
        return str;
    }
};

int main() {
    Solution solution;
    vector<string> problems{"3[a]2[bc]",
                            "3[a2[c]]",
                            "2[abc]3[cd]ef",
                            "3[z]2[2[y]pq4[2[jk]e1[f]]]ef"};
    for (auto s : problems) {
        cout << s << ": " << solution.decodeString(s) << endl;
    }
    return 0;
}