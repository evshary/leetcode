class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int largest_area = 0;
        for (int i = 0; i <= heights.size(); i++) {
            // In the final run, use 0 to clear the stack and calculate all the possible area 
            int h = (i == heights.size())? 0 : heights[i];
            while(!s.empty() && h < heights[s.top()]) {
                // get the current height
                int cur_height = heights[s.top()];
                s.pop();
                // calculate the max possible width
                int prev_idx = (s.empty()) ? -1 : s.top();
                int cur_width = i - prev_idx - 1;
                // calculate the area and compare
                int cur_area = cur_height * cur_width;
                largest_area = max(largest_area, cur_area);
            }
            s.push(i);
        }
        return largest_area;
    }
};