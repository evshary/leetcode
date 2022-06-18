class Solution {
private:
    void traverse(vector<vector<int>>& result, vector<int>& arr, vector<int>& nums, int bitmask) {
        if (arr.size() == nums.size()) {
            result.push_back(arr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if ((bitmask & (1 << i)) == 0) {
                arr.push_back(nums[i]);
                traverse(result, arr, nums, bitmask | (1<<i));
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // TC:O(N!), SC:O(N), while N = nums.size()
        vector<vector<int>> result;
        vector<int> arr;
        traverse(result, arr, nums, 0);
        return result;
    }
};