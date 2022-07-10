class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        int total_num = matrix.size() * matrix[0].size();
        vector<int> ans;
        while (true) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[up][i]);
            }
            up++;
            if (ans.size() == total_num) break;
            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (ans.size() == total_num) break;
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[down][i]);
            }
            down--;
            if (ans.size() == total_num) break;
            for (int i = down; i >= up; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if (ans.size() == total_num) break;
        }
        return ans;
    }
};