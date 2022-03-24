class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int thin = 0, heavy = people.size()-1;
        int boat_num = 0;
        while (thin <= heavy) {
            if (thin != heavy && people[thin] + people[heavy] <= limit) {
                thin++;
            }
            heavy--;
            boat_num++;
        }
        return boat_num;
    }
};