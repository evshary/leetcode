class Solution {
public:
    int longestMountain(vector<int>& arr) {
#if 1
        vector<int> up(arr.size(), 0), down(arr.size(), 0);
        int max_len = 0;
        for (int i = arr.size()-2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                down[i] = down[i+1] + 1;
            }
        }
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i-1]) {
                up[i] = up[i-1] + 1;
            }
            if (up[i] && down[i]) {
                max_len = max(max_len, up[i]+down[i]+1);
            }
        }
        return max_len;
#else
        int start = 0, end = 1;
        int max_len = 0;
        while (end < arr.size()) {
            if (arr[end] > arr[end-1]) {
                if (end >= 2 && arr[end-2] > arr[end-1]) {
                    start = end - 1;
                }
            } else if (arr[end] == arr[end-1]) {
                start = end;
            } else if (arr[end] < arr[end-1]) {
                if (end - start >= 2) {
                    max_len = max(max_len, end-start+1);
                } else {
                    start = end;
                }
            }
            end++;
        }
        return max_len;
#endif
    }
};