class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0, tmp_sum = 0, start = 0;
        unordered_map<int, int> hash_table;
        for (int j = 0; j < nums.size(); j++) {
            while (hash_table.find(nums[j]) != hash_table.end()) {
                tmp_sum -= nums[start];
                hash_table.erase(nums[start]);
                start++;
            }
            tmp_sum += nums[j];
            hash_table[nums[j]] = 1;
            res = max(res, tmp_sum);
        }
        return res;
    }
};