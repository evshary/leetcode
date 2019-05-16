#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#if 1 // find to get the maximum goal (from discussion)
    bool canJump(vector<int>& nums) {
        int i, max_goal;
        for (i = 0, max_goal = 0; i < nums.size() && i <= max_goal; i++) {
            max_goal = max(max_goal, i + nums[i]);
        }
        return i == nums.size();
    }
#elif 1 // reverse the vector and get the min solution (from discussion)
    bool canJump(vector<int>& nums) {
        int goal = nums.size()-1;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] + i >= goal)
                goal = i;
        }
        if (!goal)
            return true;
        else
            return false;
    }
#else
    bool canJump(vector<int>& nums) {
        bool pass_game = true;
        int counter = 0;
        for (vector<int>::reverse_iterator it = nums.rbegin() + 1; it != nums.rend(); it++) {
            // We only need to recount the counter while the pass_game is true and met 0.
            if(pass_game && *it == 0) {
                pass_game = false;
                counter = 0;
            } else if (pass_game == false) {
                counter++;
                if (counter < *it)
                    pass_game = true;
            }
        }
        return pass_game;
    }
#endif
};

int main() {
    vector<vector<int>> problems{{2,3,1,1,4},{3,2,1,0,4},{0},{1,1,1,0},{2,0,1,0,1}};
    Solution solution;
    for (auto p : problems) {
        if (solution.canJump(p))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}