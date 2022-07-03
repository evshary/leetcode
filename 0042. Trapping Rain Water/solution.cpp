class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> ms;
        int available_water = 0;
        for (int i = 0; i < height.size(); i++) {
            int last_wall = 0;
            while (!ms.empty() && height[ms.top()] <= height[i]) {
                available_water += (i - ms.top() - 1) * (height[ms.top()] - height[last_wall]);
                last_wall = ms.top();
                ms.pop();
            }
            if (!ms.empty()) {
                available_water += (i - ms.top() - 1) * (height[i] - height[last_wall]); 
            }
            ms.push(i);
        }
        return available_water;
    }
};