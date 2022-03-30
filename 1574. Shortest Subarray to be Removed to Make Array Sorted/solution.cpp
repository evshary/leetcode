class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // find the non-decreasing contiguous subarr from left
        int left = 0;
        while (left + 1 < arr.size() && arr[left] <= arr[left+1]) left++;
        if (left == arr.size() - 1) return 0;
        // find the non-decreasing contiguous subarr from right
        int right = arr.size()-1;
        while (right-1 >= 0 && arr[right-1] <= arr[right]) right--;
        int answer = min((int)arr.size() - left - 1, right);
        // Move two pointers and find the min subarr which can be removed
        int i = 0, j = right;
        while (i <= left && j < arr.size()) {
            if (arr[j] < arr[i]) {
                j++;
                continue;
            }
            answer = min(answer, j - i - 1);
            i++;
        }
        return answer;
    }
};