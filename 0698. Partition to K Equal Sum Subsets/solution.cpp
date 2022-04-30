class Solution {
private:
    vector<int> bucket;
    int target;
    bool put(vector<int>& nums, int n) {
        for (int i = 0; i < bucket.size(); i++) {
            if (nums[n] + bucket[i] > target) continue;
            bucket[i] += nums[n];
            if (n == nums.size()-1) return true;
            if (put(nums, n+1)) {
                return true;
            } else {
                bucket[i] -= nums[n];
                // Note: if this bucket is empty, no need to try other bucket
                if (bucket[i] == 0) return false;
            }
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto n : nums) sum += n;
        target = sum / k;
        if (target * k != sum) return false;
        bucket = vector<int>(k, 0);
        // Put number into buckets
        return put(nums, 0);
    }
};