#include <iostream>
#include <vector>
using namespace std;

#define RIGHT    0
#define DOWN     1
#define LEFT     2
#define UP       3
#define DIR_SUM  4

class Map {
public:
    Map(vector<vector<int>>& new_map) {
        min_row = min_col = 0;
        max_row = new_map.size();
        if (max_row != 0)
            max_col = new_map[0].size();
        map_size = max_col * max_row;
    }
    bool inMap(int row, int col) {
        if (row >= min_row && row < max_row &&
            col >= min_col && col < max_col)
            return true;
        return false;
    }
    int getOriginMapSize() {
        return map_size;
    }
    void shrinkMap(int sides) {
        if (sides == 0) min_row++; // up
        else if (sides == 1) max_col--; // right
        else if (sides == 2) max_row--; // down;
        else if (sides == 3) min_col++; // left
    }
private:
    int min_row;
    int max_row;
    int min_col;
    int max_col;
    int map_size;
};

class Guide {
public:
    Guide() {
        cur_direction = RIGHT;
    }
    void move_forward(int& row_idx, int& col_idx) {
        switch(cur_direction) {
            case RIGHT: col_idx++; break;
            case DOWN: row_idx++; break;
            case LEFT: col_idx--; break;
            case UP: row_idx--; break;
        }
    }
    void redirect(int& row_idx, int& col_idx, Map& map) {
        switch(cur_direction) {
            case RIGHT: row_idx++;col_idx--;map.shrinkMap(0); break;
            case DOWN: row_idx--;col_idx--;map.shrinkMap(1); break;
            case LEFT: row_idx--;col_idx++;map.shrinkMap(2); break;
            case UP: row_idx++;col_idx++;map.shrinkMap(3); break;
        }
        cur_direction = (cur_direction+1)%DIR_SUM;
    }
private:
    int cur_direction;
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = {};
        Map map(matrix);
        if (map.getOriginMapSize() == 0) return result;
        Guide guide;
        int row_idx = 0, col_idx = 0;
        while (result.size() < map.getOriginMapSize()) {
            while (map.inMap(row_idx, col_idx)) {
                result.push_back(matrix[row_idx][col_idx]);
                guide.move_forward(row_idx, col_idx);
            }
            guide.redirect(row_idx, col_idx, map);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix{
                               {1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}
                              };
    Solution s;
    for(auto num : s.spiralOrder(matrix)) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}