#if 1
class Solution {
private:
    void traverse(vector<vector<int>> &result, vector<int> arr, int n, int max_n, int k) {
        if (k == 0) {
            result.push_back(arr);
            return;
        }
        for (int i = n; k <= max_n - i + 1 /*pruning*/ ; i++) {
            arr.push_back(i);
            traverse(result, arr, i+1, max_n, k-1);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        traverse(result, vector<int>{}, 1, n, k);
        return result;
    }
};
#else
class Solution {
private:
    void traverse(vector<vector<int>> &result, vector<int> arr, int n, int max_n, int k) {
        if (k == 0) {
            result.push_back(arr);
            return;
        }
        if (n > max_n || k > max_n - n + 1) return;
        traverse(result, arr, n+1, max_n, k);
        arr.push_back(n);
        traverse(result, arr, n+1, max_n, k-1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        traverse(result, vector<int>{}, 1, n, k);
        return result;
    }
};
#endif