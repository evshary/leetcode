class Solution {
private:
    bool ableToShipWithinDays(vector<int>& weights, int weight, int days) {
        int pkg = 0;
        for (int i = 0; i < days; i++) {
            int load = weight;
            while (pkg < weights.size()) {
                if (load - weights[pkg] >= 0) {
                    load -= weights[pkg];
                    pkg++;
                } else {
                    break;
                }
            }
        }
        return (pkg == weights.size())? true:false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int max_weight, min_weight = 0;
        for (auto w : weights) {
            min_weight = max(min_weight, w);
            max_weight += w;
        }
        while (min_weight <= max_weight) {
            int mid_weight = min_weight + (max_weight-min_weight)/2;
            if (ableToShipWithinDays(weights, mid_weight, days) == true) {
                max_weight = mid_weight - 1;
            } else {
                min_weight = mid_weight + 1;
            }
        }
        return min_weight;
    }
};
