class Solution {
private:
	void findMin_r(vector<int>& nums, int left, int right, int &min_value) {
		if (right < left) return;
		if (left == right || left + 1 == right) {
			min_value = min({min_value, nums[left], nums[right]});
			return;
		}
		int mid = left + (right - left)/2;
		if (nums[right] > nums[mid] && nums[mid] > nums[left]) {
			min_value = min(min_value, nums[left]);
			return;
		} else if (nums[left] > nums[right] && nums[right] > nums[mid]) {
			min_value = min(min_value, nums[mid]);
			findMin_r(nums, left+1, mid-1, min_value);
		} else if (nums[mid] > nums[left] && nums[left] > nums[right]) {
			min_value = min(min_value, nums[right]);
			findMin_r(nums, mid+1, right-1, min_value);
		}
	}
public:
    int findMin(vector<int>& nums) {
        int result = INT_MAX;
        findMin_r(nums, 0, nums.size()-1, result);
        return result;
    }
};