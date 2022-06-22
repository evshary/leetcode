class Solution {
private:
    void traverse(vector<vector<int>>& result, vector<int>& path, vector<int>& nums, int bitmask) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int cur_i = i;
            if (((1 << i) & bitmask) == 0) {
                while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
                path.push_back(nums[i]);
                traverse(result, path, nums, (1<<cur_i)|bitmask);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        traverse(result, path, nums, 0);
        return result;
    }
};