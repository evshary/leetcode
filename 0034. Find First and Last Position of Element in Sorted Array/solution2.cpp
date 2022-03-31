#if 1
class Solution {
    // Will return the most left target if target is found
    // or will return the index of the number which is larger than target
    int binarySearch(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target <= nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return start;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearch(nums, target);
        int right = binarySearch(nums, target+1) - 1;
        if (left < nums.size() && nums[left] == target) {
            return {left, right};
        } else {
            return {-1, -1};
        }
    }
};
#else
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        if (nums.size() == 0) return ans;
        // find the valid number
        int start = 0, mid = 0, end = nums.size() - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target < nums[mid]) {
                end = mid - 1;
            } else if (target > nums[mid]) {
                start = mid + 1;
            } else { // target == nums[mid]
                break;
            }
        }
        // if not found, return {-1, -1}
        if (nums[mid] != target) return ans;
        // extend from found index to left and right
        ans[0] = ans[1] = mid;
        while (ans[0] > 0 && nums[ans[0]-1] == target) ans[0]--;
        while (ans[1] < nums.size()-1 && nums[ans[1]+1] == target) ans[1]++;
        return ans;
    }
};
#endif