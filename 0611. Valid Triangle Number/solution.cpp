class Solution {
public:
    int triangleNumber(vector<int>& nums) {
#if 1 // Simpler
        int answers = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i >= 2; i--) {
            int start = 0, end = i-1;
            while (start < end) {
                if (nums[end] + nums[start] > nums[i]) {
                    answers += end - start;
                    end--;
                } else {
                    start++;
                }
            }
        }
        return answers;
#elif 0
        int answers = 0;
        sort(nums.begin(), nums.end());
        int start = 0, end = 0;
        for (int i = 0; i < nums.size(); i++) {
            start = i+1;
            end = i+2;
            while (start <= end && end <= nums.size()) {
                if (start == end) end++;
                while (end < nums.size() && nums[i] + nums[start] > nums[end]) {
                    end++;
                }
                answers += end - start - 1;
                start++;
            }
        }
        return answers;
#else  // TLE
        int answers = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] > nums[k])
                        answers++;
                    else
                        break;
                }
            }
        }
        return answers;
#endif
    }
};