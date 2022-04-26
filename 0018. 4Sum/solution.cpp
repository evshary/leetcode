#if 1 // recursive for kSum
class Solution {
private:
    vector<vector<int>> result;
    void kSum(vector<int>& nums, int target, int k, int left, int right, vector<int> &temp) {
        if (k == 2) {
            int remain = target;
            for (auto n : temp) remain -= n;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == remain) {
                    temp.push_back(nums[left++]);
                    temp.push_back(nums[right--]);
                    result.push_back(temp);
                    temp.pop_back();
                    temp.pop_back();
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                } else if (sum > remain) {
                    right--;
                } else if (sum < remain) {
                    left++;
                }
            }
        } else {
            while (left < right) {
                temp.push_back(nums[left++]);
                kSum(nums, target, k-1, left, right, temp);
                temp.pop_back();
                while (left < right && nums[left] == nums[left-1]) left++;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        kSum(nums, target, 4, 0, nums.size()-1, temp);
        return result;
    }
};
#else
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int remain = target - nums[i] - nums[j];
                int left = j+1, right = nums.size()-1;
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum == remain) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        left++, right--;
                    } else if (sum > remain) {
                        right--;
                    } else if (sum < remain) {
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
#endif
