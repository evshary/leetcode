class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> power_result;

        for (int i = lo; i <= hi; i++) {
            int power = 0;
            int x = i;
            while (x != 1) {
                if (x % 2 == 0)
                    x = x / 2;
                else
                    x = 3 * x + 1;
                power++;
            }
            power_result.push_back(make_pair(power, i));
        }
        // sort power_result
        sort(power_result.begin(), power_result.end());

        return power_result[k-1].second;
    }
};