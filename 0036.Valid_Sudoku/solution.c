#include <stdio.h>
#include <stdbool.h>

enum {
    BOARD_ROW = 0,
    BOARD_COL,
    BOARD_BOX,
    BOARD_MAX,
};

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    unsigned char check_map[BOARD_MAX][9][9] = {0};
    int box_idx, cur_num;
    for (int i = 0; i < boardColSize; i++) {
        for (int j = 0; j < boardRowSize; j++) {
            if (board[i][j] != '.') {
                box_idx = (i/3)*3 + j/3;
                cur_num = board[i][j] - '0' - 1;
                if (check_map[BOARD_ROW][j][cur_num] == 0)
                    check_map[BOARD_ROW][j][cur_num] = 1;
                else
                    return false;
                if (check_map[BOARD_COL][i][cur_num] == 0)
                    check_map[BOARD_COL][i][cur_num] = 1;
                else
                    return false;
                if (check_map[BOARD_BOX][box_idx][cur_num] == 0)
                    check_map[BOARD_BOX][box_idx][cur_num] = 1;
                else
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    char *board[9] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    if (isValidSudoku((char **)board, 9, 9))
        printf("true\r\n");
    else
        printf("false\r\n");
    return 0;
}