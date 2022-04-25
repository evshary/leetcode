class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (mid >= 1 && nums[mid] == nums[mid-1]) {
                mid = mid - 1;
            } else if (mid < nums.size()-1 && nums[mid] == nums[mid+1]) {
                mid = mid;
            } else {
                break;
            }
            if (mid % 2 == 0) {
                start = mid + 2;
            } else if (mid % 2 == 1) {
                end = mid - 1;
            }
        }
        return nums[mid];
    }
};