#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Ref: 0084
int maxRectInHistogram(char* heights, int heightsSize) {
    int newSize = heightsSize+2;
    int new_heights[newSize];
    for (int i = 0; i < heightsSize; i++){
        new_heights[i+1] = heights[i];
    }
    new_heights[0] = new_heights[newSize - 1] = 0;
    int stack[newSize];
    int next_ptr = 0;
    int max_size = 0;
    int cur_weight, cur_height;
    for (int i = 0; i < newSize; i++) {
        while (next_ptr > 1 && new_heights[stack[next_ptr-1]] >= new_heights[i]) {
            cur_height = new_heights[stack[--next_ptr]]; // get the height and pop the stack
            cur_weight = i - stack[next_ptr-1] - 1;
            max_size = fmax(max_size, cur_weight * cur_height);
        }
        stack[next_ptr++] = i; // push stack
    }
    return max_size;
}

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if (matrixRowSize == 0 || matrixColSize == 0)
        return 0;
    int return_size = 0;
    char dp_map[matrixRowSize][matrixColSize];
    for (int j = 0; j < matrixColSize; j++) {
        for (int i = 0; i < matrixRowSize; i++) {
            if (i == 0)
                dp_map[i][j] = matrix[i][j] - '0';
            else {
                if (matrix[i][j] == '1')
                    dp_map[i][j] = dp_map[i-1][j] + 1;
                else
                    dp_map[i][j] = matrix[i][j] - '0';
            }
        }
    }
#if 0
    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            printf("%d ", dp_map[i][j]);
        }
        printf("\n");
    }
#endif
    for (int i = 0; i < matrixRowSize; i++) {
        return_size = fmax(return_size, maxRectInHistogram(dp_map[i], matrixColSize));
    }
    return return_size;
}

int main() {
    #define MATRIX_COL 5
    char origin_matrix[][MATRIX_COL] = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    int row_size = sizeof(origin_matrix)/sizeof(origin_matrix[0]);
    int col_size = MATRIX_COL;
    char **matrix = malloc(row_size * sizeof(char *));
    for (int i = 0; i < row_size; i++) {
        matrix[i] = malloc(col_size);
        for (int j = 0; j < col_size; j++) {
            matrix[i][j] = origin_matrix[i][j];
        }
    }
    printf("maximalRectangle=%d\n", maximalRectangle(matrix, row_size, col_size));
    return 0;
}