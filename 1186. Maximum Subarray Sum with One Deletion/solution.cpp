#if 1 // space O(1)
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int max_w_del = arr[0];  // at most 1 delete
        int max_wo_del = arr[0]; // no delete
        int max_result = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            max_w_del = max(max_w_del + arr[i], max_wo_del);
            max_wo_del = max(arr[i], max_wo_del + arr[i]);
            max_result = max({max_result, max_w_del, max_wo_del});
        }
        return max_result;
    }
};
#else
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if (arr.size() == 1) return arr[0];
        vector<int> dp(arr.size());
        vector<int> dp_r(arr.size());
        dp[0] = arr[0];
        dp_r[arr.size()-1] = arr[arr.size()-1];
        int max_num = INT_MIN;
        for (int i = 1; i < arr.size(); i++) {
            dp[i] = (dp[i-1] < 0)? arr[i]:dp[i-1]+arr[i];
            max_num = max(max_num, dp[i]);
        }
        for (int i = arr.size()-2; i >= 0; i--) {
            dp_r[i] = (dp_r[i+1] < 0)? arr[i]:dp_r[i+1]+arr[i];
        }
        for (int i = 1; i < arr.size()-1; i++) {
            if (arr[i] < 0) {
                max_num = max(max_num, dp[i-1]+dp_r[i+1]);
            }
        }
        return max_num;
    }
};
#endif