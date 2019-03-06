#include <stdio.h>
#include <stdlib.h>


#define DIVIDE_AND_CONQUER 0
#define DYNAMIC_PROGRAM    1

#if DYNAMIC_PROGRAM
#define min(x,y) ((x)<(y))?(x):(y)
int minFallingPathSum(int** A, int ARowSize, int *AColSizes) {
    int tmp_min;
    for (int i = 1; i < ARowSize; i++) {
        for (int j = 0; j < ARowSize; j++) {
            tmp_min = A[i-1][j];
            if (j > 0)
                tmp_min = min(tmp_min, A[i-1][j-1]);
            if (j < ARowSize-1)
                tmp_min = min(tmp_min, A[i-1][j+1]);
            A[i][j] += tmp_min;
        }
    }
    tmp_min = A[ARowSize-1][0];
    for (int i = 1; i < ARowSize; i++) {
        tmp_min = min(A[ARowSize-1][i], tmp_min);
    }
    return tmp_min;
}
#endif /*DYNAMIC_PROGRAM*/

#if DIVIDE_AND_CONQUER
#define min(x,y) ((x)<(y))?(x):(y)
int getMinSum_r(int** memo, int** A, int maxSize, int row, int col) {
    int ret_val;
    //printf("row=%d, col=%d\r\n", row, col);
    if (row + 1 == maxSize) {
        //printf("A[%d][%d]=%d\n", row, col, A[row][col]);
        return A[row][col];
    }
    if (memo[row][col] != 0)
        return memo[row][col];
    ret_val = getMinSum_r(memo, A, maxSize, row+1, col);
    if (col - 1 >= 0)
        ret_val = min(ret_val, getMinSum_r(memo, A, maxSize, row+1, col-1));
    if (col + 1 < maxSize)
        ret_val = min(ret_val, getMinSum_r(memo, A, maxSize, row+1, col+1));
    //printf("ret_val=%d A[%d][%d]=%d\n", ret_val, row, col, A[row][col]);
    memo[row][col] = ret_val + A[row][col];
    return memo[row][col];
}

int minFallingPathSum(int** A, int ARowSize, int *AColSizes) {
    int **memo = malloc(ARowSize * sizeof(int *));
    for (int i = 0; i < ARowSize; i++) {
        memo[i] = malloc(ARowSize * sizeof(int));
        for (int j = 0; j < ARowSize; j++)
            memo[i][j] = 0;
    }
    int max_sum = getMinSum_r(memo, A, ARowSize, 0, 0);
    for (int i = 1; i < ARowSize; i++){
        max_sum = min(max_sum, getMinSum_r(memo, A, ARowSize, 0, i));
    }
    return max_sum;
}
#endif /*DIVIDE_AND_CONQUER*/

void initMatrix(int row_size, int col_size, int origin_matrix[row_size][col_size], int ***matrix) {
    *matrix = malloc(row_size * sizeof(int *));
    for (int i = 0; i < row_size; i++) {
        (*matrix)[i] = malloc(col_size * sizeof(int));
        for (int j = 0; j < col_size; j++) {
            (*matrix)[i][j] = origin_matrix[i][j];
        }
    }
}

int main()
{
    int **matrix;
#if 1
    #define MAX_COL_SIZE 3
    // [1,2,3],
    // [4,5,6],
    // [7,8,9]
    int origin_matrix[][MAX_COL_SIZE] = {
        { 1, 2, 3},
        { 4, 5, 6},
        { 7, 8, 9}
    };
#else
    #define MAX_COL_SIZE 2
    // [51,24]
    // [-50,82]
    int origin_matrix[][MAX_COL_SIZE] = {
        {  51, 24},
        { -50, 82}
    };
#endif
    int row_size = sizeof(origin_matrix)/(sizeof(int)*MAX_COL_SIZE);
    int col_size = MAX_COL_SIZE;
    initMatrix(row_size, MAX_COL_SIZE, origin_matrix, &matrix);
    printf("minFallPath: %d\n", minFallingPathSum(matrix, row_size, &col_size));
    return 0;
}