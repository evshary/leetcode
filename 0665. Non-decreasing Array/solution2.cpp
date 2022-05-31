class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int last_min = INT_MIN;
        int cur_min = INT_MIN;
        bool chance = true;
        for (auto n : nums) {
            if (n < cur_min) {
                if (!chance) return false;
                if (n < last_min) {
                    // ignore
                } else {
                    cur_min = n;
                }
                chance = false;
            } else {
                last_min = cur_min;
                cur_min = n;
            }
        }
        return true;
    }
};