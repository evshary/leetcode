1. If the input parameter is pointer to pointer, you should make sure the parameter is allocated, not just an array. The difference betweeen pointer to pointer and 2D array is important, although they can use board[i][j].
2. I use an 3D array to record whether the number is repeat or not. I think I can use 2D array instead of 3D, but this is not easy to understand.
3. My first result is below:
  - Runtime: 16 ms, faster than 36.46% of C online submissions for Valid Sudoku.
  - Memory Usage: 9.6 MB, less than 100.00% of C online submissions for Valid Sudoku.
  However, if I move the declartion out of array, it becomes faster more.
  - Runtime: 8 ms, faster than 86.19% of C online submissions for Valid Sudoku.
  - Memory Usage: 9.6 MB, less than 100.00% of C online submissions for Valid Sudoku.