#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize == 0 || gridColSize == 0)
        return 0;
    int dp_map[gridRowSize][gridColSize];
    dp_map[0][0] = grid[0][0];
    for (int i = 1; i < gridRowSize; i++) {
        dp_map[i][0] = dp_map[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < gridColSize; j++) {
        dp_map[0][j] = dp_map[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            dp_map[i][j] = fmin(dp_map[i-1][j], dp_map[i][j-1]) + grid[i][j];
        }
    }
#if 0
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            printf("%d ", dp_map[i][j]);
        }
        printf("\n");
    }
#endif
    return dp_map[gridRowSize-1][gridColSize-1];
}

int main() {
#if 1
    #define COL_SIZE 3
    int origin_grid[][COL_SIZE] = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
#else
    #define COL_SIZE 2
    int origin_grid[][COL_SIZE] = {
        {1,2},
        {1,1}
    };
#endif
    int row_size = sizeof(origin_grid)/sizeof(origin_grid[0]);
    int col_size = COL_SIZE;
    int **grid = malloc(sizeof(int *) * row_size);
    for (int i = 0; i < row_size; i++) {
        grid[i] = malloc(sizeof(int) * col_size);
        for (int j = 0; j < col_size; j++) {
            grid[i][j] = origin_grid[i][j];
        }
    }
    printf("minPathSum=%d\n", minPathSum(grid, row_size, col_size));
    return 0;
}