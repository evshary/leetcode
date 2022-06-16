class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int head = 0, tail = height.size() - 1;
        while (head < tail) {
            int area = min(height[head], height[tail]) * (tail - head);
            max_area = max(max_area, area);
            if (height[head] <= height[tail]) {
                head++;
            } else {
                tail--;
            }
        }
        return max_area;
    }
};