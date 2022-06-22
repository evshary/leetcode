class Solution {
private:
    void traverse(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int n) {
        if (n == nums.size()) {
            result.push_back(path);
            return;
        }
        int repeat_num = 1;
        while (n+1 < nums.size() && nums[n+1] == nums[n]) {
            repeat_num++;
            n++;
        }
        traverse(result, path, nums, n+1);
        for (int i = 0; i < repeat_num; i++) {
            path.push_back(nums[n]);
            traverse(result, path, nums, n+1);
        }
        for (int i = repeat_num; i > 0; i--) {
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        traverse(result, path, nums, 0);
        return result;
    }
};