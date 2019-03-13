#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkValid(char ** board, int row, int column, char target) {
    /* check row */
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == target)
            return false;
    }
    /* check column */
    for (int i = 0; i < 9; i++) {
        if (board[i][column] == target)
            return false;
    }
    /* check block */
    int start_row = (row / 3) * 3;
    int start_column = (column / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_column; j < start_column + 3; j++) {
            if (board[i][j] == target)
                return false;
        }
    }
    return true;
}

bool solveSudoku_r(char** board, int index) {
    int row, column;
    if (index >= 81)
        return true;
    row = index / 9;
    column = index % 9;
    if (board[row][column] != '.')
        return solveSudoku_r(board, index + 1);
    for (char ch = '1'; ch <= '9'; ch++) {
        if (!checkValid(board, row, column, ch))
            continue;
        board[row][column] = ch;
        if (solveSudoku_r(board, index + 1)) {
            return true;
        }
        board[row][column] = '.';
    }
    // should never reach here.
    return false;
}

void solveSudoku(char** board, int boardRowSize, int *boardColSizes) {
    solveSudoku_r(board, 0);
    return;
}

int main() {
    #define ROW_NUM 9
    #define COL_NUM 9
    char array[][COL_NUM] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    char **board = malloc(ROW_NUM * sizeof(char *));
    int *col_size = malloc(ROW_NUM * sizeof(int));
    for (int i = 0; i < ROW_NUM; i++) {
        board[i] = malloc(COL_NUM * sizeof(char));
        col_size[i] = COL_NUM;
        for (int j = 0; j < COL_NUM; j++) {
            board[i][j] = array[i][j];
        }
    }
    solveSudoku(board, ROW_NUM, col_size);
    for (int i = 0; i < ROW_NUM; i++) {
        for (int j = 0; j < col_size[j]; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
        free(board[i]);
    }
    free(board);
    return 0;
}