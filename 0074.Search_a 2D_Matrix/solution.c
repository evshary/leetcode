#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int target_row = matrixRowSize-1;
    if (matrixColSize == 0) return false;
    //printf("matrixRowSize=%d matrixColSize=%d\n", matrixRowSize, matrixColSize);
    for (int i = 0; i < matrixRowSize; i++) {
        //printf("i=%d, target=%d, matrix[i][0]=%d\n", i, target, matrix[i][0]);
        if (matrix[i][0] > target) {
            if (i == 0)
                return false;
            target_row = i - 1;
            break;
        } else if (matrix[i][0] == target)
            return true;
    }
    for (int i = 0; i < matrixColSize; i++) {
        //printf("target_row=%d, matrix[target_row][i]=%d\n", target_row, matrix[target_row][i]);
        if (matrix[target_row][i] == target)
            return true;
    }
    return false;
}

void initMatrix(int row_size, int col_size, int origin_matrix[row_size][col_size], int ***matrix) {
    *matrix = malloc(row_size * sizeof(int *));
    for (int i = 0; i < row_size; i++) {
        (*matrix)[i] = malloc(col_size * sizeof(int));
        for (int j = 0; j < col_size; j++) {
            (*matrix)[i][j] = origin_matrix[i][j];
        }
    }
}

void printGraph(int **graph, int row_size, int *col_size) {
    for (int i = 0; i < row_size; i++) {
        printf("[");
        for (int j = 0; j < col_size[i]; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("]\n");
    }
}

int main()
{
    int **matrix;
#if 1
    #define MAX_COL_SIZE 4
    // [1,   3,  5,  7],
    // [10, 11, 16, 20],
    // [23, 30, 34, 50]
    int origin_matrix[][MAX_COL_SIZE] = {
        { 1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };
    int target = 30;
#else
    #define MAX_COL_SIZE 1
    // [1],
    // [3],
    int origin_matrix[][MAX_COL_SIZE] = {
        {1},
        {3},
    };
    int target = 3;
#endif
    int row_size = sizeof(origin_matrix)/(sizeof(int)*MAX_COL_SIZE);
    initMatrix(row_size, MAX_COL_SIZE, origin_matrix, &matrix);
    if (searchMatrix(matrix, row_size, MAX_COL_SIZE, target))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}