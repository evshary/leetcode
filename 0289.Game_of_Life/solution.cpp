#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int live_neighbor_cnt;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                live_neighbor_cnt = ((i > 0 && j > 0)?board[i-1][j-1]&0x01:0) +
                                    ((i > 0)?board[i-1][j]&0x01:0) +
                                    ((i > 0 && j < board[i-1].size()-1)?board[i-1][j+1]&0x01:0) +
                                    ((j > 0)?board[i][j-1]&0x01:0) +
                                    ((j < board[i].size()-1)?board[i][j+1]&0x01:0) +
                                    ((i < board.size()-1 && j > 0)?board[i+1][j-1]&0x01:0) +
                                    ((i < board.size()-1)?board[i+1][j]&0x01:0) +
                                    ((i < board.size()-1 && j < board[i].size()-1)?board[i+1][j+1]&0x01:0);
                if (live_neighbor_cnt == 2 && (board[i][j] & 0x01))
                    board[i][j] |= 0x02;
                if (live_neighbor_cnt == 3)
                    board[i][j] |= 0x02;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] >>= 1;
            }
        }
        return;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> board{{0,1,0},
                              {0,0,1},
                              {1,1,1},
                              {0,0,0}};
    solution.gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}