class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> myset(arr.begin(), arr.end());
        int result = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i+1; j < arr.size(); j++) {
                int l = 2, a = arr[i], b = arr[j];
                while (myset.count(a+b)) {
                    b = a + b;
                    a = b - a; // a = old b
                    l++;
                }
                result = max(result, l);
            }
        }
        return (result > 2)? result:0;
    }
};
