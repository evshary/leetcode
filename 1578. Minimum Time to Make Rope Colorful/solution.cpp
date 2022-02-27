class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total_time = 0;
        int same_color_time = 0;
        int max_color_time = 0;
        int color_size = colors.size();
        
        for (int i = 0; i < color_size; i++) {
            if (i > 0 && colors[i] != colors[i-1]) {
                total_time += same_color_time - max_color_time;
                same_color_time = max_color_time = 0;
            }
            same_color_time += neededTime[i];
            max_color_time = max(max_color_time, neededTime[i]);
        }
        total_time += same_color_time - max_color_time;
        return total_time;
#if 0  // too complicated
        bool consecutive = false;
        for (int i = 1; i < color_size; i++) {
            if (colors[i] == colors[i-1]) {
                same_color_time += neededTime[i-1];
	            max_color_time = max(max_color_time, neededTime[i-1]);
	            consecutive = true;
            } else {
                if (consecutive == true) {
                    same_color_time += neededTime[i-1];
                    max_color_time = max(max_color_time, neededTime[i-1]);
	                total_time += same_color_time - max_color_time;
	                consecutive = false;
                    same_color_time = 0;
                    max_color_time = 0;
                }
            }
            if (consecutive && i == color_size-1) {
                same_color_time += neededTime[i];
                max_color_time = max(max_color_time, neededTime[i]);
                consecutive = false;
                total_time += same_color_time - max_color_time;
            }
        }
        
        return total_time;
#endif
    }
};