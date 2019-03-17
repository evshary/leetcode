#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int tmp_num, tmp_size;
    for (int i = 0; i < matrixRowSize/2; i++) {
        //printf("i = %d\n", i);
        tmp_size = matrixColSizes[i]-i-1;
        for (int j = i; j < tmp_size; j++) {
            tmp_num = matrix[tmp_size-j+i][i];
            //printf("1. %d %d\n", tmp_size-j+i, i);
            matrix[tmp_size-j+i][i] = matrix[tmp_size][tmp_size-j+i];
            //printf("2. %d %d\n", tmp_size, tmp_size-j+i);
            matrix[tmp_size][tmp_size-j+i] = matrix[j][tmp_size];
            //printf("3. %d %d\n", j, tmp_size);
            matrix[j][tmp_size] = matrix[i][j];
            //printf("4. %d %d\n", i, j);
            matrix[i][j] = tmp_num;
        }
    }
}

int main() {
#if 0
    #define ROW_SIZE 3
    int ori_matrix[][ROW_SIZE] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
#elif 0
    #define ROW_SIZE 4
    int ori_matrix[][ROW_SIZE] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
#elif 1
    #define ROW_SIZE 5
    int ori_matrix[][ROW_SIZE] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
#endif
    int **matrix = malloc(sizeof(int *) * ROW_SIZE);
    int *col = malloc(sizeof(int) * ROW_SIZE);
    for (int i = 0; i < ROW_SIZE; i++) {
        col[i] = sizeof(ori_matrix[i])/sizeof(ori_matrix[i][0]);
        matrix[i] = malloc(sizeof(int) * col[i]);
        for (int j = 0; j < col[i]; j++) {
            matrix[i][j] = ori_matrix[i][j];
        }
    }
    rotate(matrix, ROW_SIZE, col);
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < col[i]; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}