class Solution {
private:
    void traverse(vector<vector<int>>& result, vector<int> arr, int sum, int num, int n, int k) {
        if (k == 0) {
            if (sum == n) result.push_back(arr);
            return;
        }
        for (int i = num; k <= 9 - i + 1 && sum < n; i++) {
            arr.push_back(i);
            sum += i;
            traverse(result, arr, sum, i+1, n, k-1);
            arr.pop_back();
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        traverse(result, vector<int>{}, 0, 1, n, k);
        return result;
    }
};