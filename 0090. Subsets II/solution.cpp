#if 1 // simplify
class Solution {
    void traverse(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int> current) {
        if (idx <= nums.size()) {
            ans.push_back(current);
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            traverse(ans, nums, i+1, current);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        traverse(ans, nums, 0, {});
        return ans;
    }
};
#else
class Solution {
private:
    void traverse(vector<vector<int>>& ans, vector<int>& counts, int n, vector<int> current) {
        if (n > 10) {
            ans.push_back(current);
        } else if (counts[n+10] == 0) {
            traverse(ans, counts, n+1, current);
        } else {
            for (int i = 0; i <= counts[n+10]; i++) {
                traverse(ans, counts, n+1, current);
                current.push_back(n);
            }
            for (int i = 0; i <= counts[n+10]; i++) {
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> counts(21, 0);
        for (auto n : nums) {
            counts[n+10]++;
        }
        traverse(ans, counts, -10, {});
        return ans;
    }
};
#endif