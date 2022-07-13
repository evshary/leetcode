class Solution {
private:
	bool isInvalid(vector<vector<bool>>& board, int row, int col) {
		for (int r = row; r >= 0; r--) {
			if (board[r][col] == true) return true;
		}
		int r = row - 1, c = col - 1;
		while (r >= 0 && c >= 0) {
			if (board[r][c] == true) return true;
			r--, c--;
		}
		r = row - 1, c = col + 1;
		while (r >= 0 && c < board[0].size()) {
			if (board[r][c] == true) return true;
			r--, c++;
		}
		return false;
	}
	void traverse(vector<vector<bool>>& board, int &result, int depth, int n) {
		if (depth == n) {
			result++;
			return;
		}
		for (int c = 0; c < n; c++) {
			if (isInvalid(board, depth, c)) continue;
			board[depth][c] = true;
			traverse(board, result, depth+1, n);
			board[depth][c] = false;
		}
	}
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int result = 0;
        traverse(board, result, 0, n);
        return result;
    }
};