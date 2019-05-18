#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return true;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (DFS(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    bool DFS(vector<vector<char>>& board, string& word, int w_idx, int row, int col) {
        if (w_idx >= word.size()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[w_idx])
            return false;
        int tmp = board[row][col];
        board[row][col] = 0;
        if (DFS(board, word, w_idx+1, row-1, col)) return true;
        if (DFS(board, word, w_idx+1, row+1, col)) return true;
        if (DFS(board, word, w_idx+1, row, col-1)) return true;
        if (DFS(board, word, w_idx+1, row, col+1)) return true;
        board[row][col] = tmp;
        return false;
    }
};

int main() {
    vector<vector<char>> board{{'A','B','C','E'},
                               {'S','F','C','S'},
                               {'A','D','E','E'}
                              };
    string word = "ABCCED";
    Solution solution;
    if (solution.exist(board, word))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}