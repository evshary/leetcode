class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            int step = i;
            int row = startPos[0], col = startPos[1];
            while (step < s.size()) {
                if (s[step] == 'L') col--;
                else if (s[step] == 'R') col++;
                else if (s[step] == 'U') row--;
                else if (s[step] == 'D') row++;
                if (row < 0 || row >= n || col < 0 || col >= n) break;
                step++;
            }
            ans.push_back(step - i);
        }
        return ans;
    }
};