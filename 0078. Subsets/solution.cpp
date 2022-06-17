class Solution {
private:
    void traverse(vector<vector<int>>& result, vector<int>& new_set, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            result.push_back(new_set);
            return;
        }
        traverse(result, new_set, nums, idx+1);
        new_set.push_back(nums[idx]);
        traverse(result, new_set, nums, idx+1);
        new_set.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> new_set;
        traverse(result, new_set, nums, 0);
        return result;
    }
};