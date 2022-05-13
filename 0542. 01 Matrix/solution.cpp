class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[r].size(); c++) {
                if (mat[r][c] == 0) {
                    ans[r][c] = 0;
                    q.push({r,c});
                }
            }
        }
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int r = pos.first;
            int c = pos.second;
            if (r > 0 && ans[r-1][c] == -1) {
                ans[r-1][c] = ans[r][c] + 1;
                q.push({r-1, c});
            }
            if (r < mat.size() - 1 && ans[r+1][c] == -1) {
                ans[r+1][c] = ans[r][c] + 1;
                q.push({r+1, c});
            }
            if (c > 0 && ans[r][c-1] == -1) {
                ans[r][c-1] = ans[r][c] + 1;
                q.push({r, c-1});
            }
            if (c < mat[0].size() - 1 && ans[r][c+1] == -1) {
                ans[r][c+1] = ans[r][c] + 1;
                q.push({r, c+1});
            }
        }
        return ans;
    }
};