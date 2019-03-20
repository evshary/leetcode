#include <stdlib.h>
#include <stdio.h>

int** generate(int numRows, int** columnSizes) {
    int **result = malloc(sizeof(int *) * numRows);
    *columnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i++) {
        (*columnSizes)[i] = i+1;
        result[i] = malloc(sizeof(int) * (i+1));
        result[i][i] = result[i][0] = 1;
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
    }
    return result;
}

int main() {
    int **result;
    int *columnSizes;
    int numRows = 5;
    result = generate(numRows, &columnSizes);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
    free(columnSizes);
    return 0;
}