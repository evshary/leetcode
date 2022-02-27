class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph;
        // init array
        for (int i = 0; i < n; i++) {
            vector<int> init_array(n, 10001);
            init_array[i] = 0;
            graph.push_back(init_array);
        }
        // fill the edge
        for (auto e : edges) {
            graph[e[0]][e[1]] = e[2];
            graph[e[1]][e[0]] = e[2];
        }
        // Floyd-Warshall's algorithm
        for (int inter = 0; inter < n; inter++) {
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {         
                    if (graph[row][col] > graph[row][inter] + graph[inter][col])
                        graph[row][col] = graph[row][inter] + graph[inter][col];
                }
            }
        }
        // Find the minimum neighor city
        int min_neighbor_city;
        int min_neighbor_num = n;
        for (int row = 0; row < n; row++) {
            int neighbor = 0;
            for (int col = 0; col < n; col++) {
                if (row != col && graph[row][col] <= distanceThreshold)
                    neighbor++;
            }
            if (neighbor <= min_neighbor_num) {
                min_neighbor_num = neighbor;
                min_neighbor_city = row;
            }
        }
        return min_neighbor_city;
    }
};