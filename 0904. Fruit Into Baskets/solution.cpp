class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        int result = 0;
        int valid_fruit = 0;
        unordered_map<int,int> basket;
        while (right < fruits.size()) {
            int fruit_r = fruits[right];
            right++;
            // update fruit while moving right
            if (basket[fruit_r] == 0)
                valid_fruit++;
            basket[fruit_r]++; 
            while (valid_fruit > 2) {
                int fruit_l = fruits[left];
                left++;
                // update fruit while moving left
                basket[fruit_l]--;
                if (basket[fruit_l] == 0) {
                    valid_fruit--;
                }
            }
            /* Update result */
            result = max(result, right-left);
        }
        return result;
    }
};

