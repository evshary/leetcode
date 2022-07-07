class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> distance(points.size());
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i = 0; i < points.size(); i++) {
        	int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        	distance[i] = d;
        	pq.push(d);
        }
        int k_distance;
        while (!pq.empty() && k > 0) {
        	k_distance = pq.top();
        	pq.pop();
        	k--;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++) {
        	if (distance[i] <= k_distance) {
        		ans.push_back(points[i]);
        	}
        }
        return ans;
    }
};