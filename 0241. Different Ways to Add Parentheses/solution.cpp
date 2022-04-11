class Solution {
private:
    unordered_map<string,vector<int>> dp;
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> result1, result2;
                string substr = expression.substr(0, i);
                if (dp.find(substr) != dp.end()) {
                    result1 = dp[substr];
                } else {
                    result1 = diffWaysToCompute(substr);
                }
                substr = expression.substr(i + 1);
                if (dp.find(substr) != dp.end()) {
                    result2 = dp[substr];
                } else {
                    result2 = diffWaysToCompute(substr);
                }
                for (auto r1 : result1) {
                    for (auto r2 : result2) {
                        if (expression[i] == '+') {
                            result.push_back(r1 + r2);
                        } else if (expression[i] == '-') {
                            result.push_back(r1 - r2);
                        } else if (expression[i] == '*') {
                            result.push_back(r1 * r2);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(stoi(expression));
        }
        dp[expression] = result;
        return result;
    }
};