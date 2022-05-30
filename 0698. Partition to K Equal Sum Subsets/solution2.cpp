class Solution {
private:
    bool dfs(vector<int>& nums, int remain_num, int bitmask, int equal_sum, int cur_sum, unordered_map<int,int>& mem) {
        if (remain_num == 0) return true;
        if (mem.count(bitmask)) return mem[bitmask];
        bool result = false;
        for (int i = 0; i < nums.size(); i++) {
            if (!(bitmask & (1 << i)) && nums[i] + cur_sum <= equal_sum) {
                result = dfs(nums, remain_num-1, bitmask | (1 << i), equal_sum, (nums[i] + cur_sum) % equal_sum, mem);
                if (result) break;
            }
        }
        mem[bitmask] = result;
        return result;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> mem;
        int total_sum = 0;
        for (auto n : nums) total_sum += n;
        if (total_sum % k != 0) return false;
        int equal_sum = total_sum / k;
        return dfs(nums, nums.size(), 0, equal_sum, 0, mem);
    }
};