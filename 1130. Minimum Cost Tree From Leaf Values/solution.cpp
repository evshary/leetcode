class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> stack{INT_MAX};
        int res = 0;
        for (auto n : arr) {
            while (stack.back() <= n) {
                int cur = stack.back();
                stack.pop_back();
                res += cur * min(stack.back(), n);
            }
            stack.push_back(n);
        }
        for (int i = 2; i < stack.size(); i++) {
            res += stack[i] * stack[i-1];
        }
        return res;
    }
};
