class Solution {
    void dfs(int row, int col, vector<vector<int>>& graph) {
        if (row < 0 || col < 0 || row >= graph.size() || col >= graph.size())
            return;
        if (graph[row][col] == 1) {
            graph[row][col] = 0;
            dfs(row-1, col, graph);
            dfs(row+1, col, graph);
            dfs(row, col-1, graph);
            dfs(row, col+1, graph);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int graph_size = grid.size() * 3;
        vector<vector<int>> graph(graph_size, vector<int>(graph_size, 1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] == '\\') {
                    graph[i*3][j*3] = 0;
                    graph[i*3+1][j*3+1] = 0;
                    graph[i*3+2][j*3+2] = 0;
                } else if (grid[i][j] == '\/') {
                    graph[i*3][j*3+2] = 0;
                    graph[i*3+1][j*3+1] = 0;
                    graph[i*3+2][j*3] = 0;
                }
            }
        }
        int region_num = 0;
        for (int r = 0; r < graph_size; r++) {
            for (int c = 0; c < graph_size; c++) {
                if (graph[r][c] == 1) {
                    // DFS
                    dfs(r, c, graph);
                    region_num++;
                }
            }
        }
        return region_num;
    }
};
