class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> min_array;
        int min_num = nums[0];
        // record s1 into array
        for (int i = 0; i < nums.size(); i++) {
            min_num = min(min_num, nums[i]);
            min_array.push_back(min_num);
        }
        stack<int> s;
        for (int i = nums.size()-1; i >= 0; i--) {
            // remove all the s3 candidate which is less than s1
            while(!s.empty() && s.top() <= min_array[i]) {
                s.pop();
            }
            // if s2 is larger than s1
            if (nums[i] > min_array[i]) {
                // return true if s2 > s3
                if (!s.empty() && nums[i] > s.top())
                    return true;
                // take nums[i] as s3 candidate
                s.push(nums[i]);
            }
        }
        return false;
    }
};

