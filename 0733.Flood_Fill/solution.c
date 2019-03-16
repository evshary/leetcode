#include <stdio.h>
#include <stdlib.h>

static int row_size;
static int col_size;
static int origin_color;
static int new_color;

void flood_r(int **image, int sr, int sc) {
    if (sr >= row_size || sr < 0)
        return;
    if (sc >= col_size || sc < 0)
        return;
    //printf("sr=%d, sc=%d image[sr][sc]=%d, new_color=%d\n", sr, sc, image[sr][sc], new_color);
    if (image[sr][sc] != origin_color)
        return;
    image[sr][sc] = new_color;
    flood_r(image, sr-1, sc);
    flood_r(image, sr+1, sc);
    flood_r(image, sr, sc-1);
    flood_r(image, sr, sc+1);
}

int** floodFill(int** image, int imageRowSize, int imageColSize, int sr, int sc, int newColor, int** columnSizes, int* returnSize) {
    int **new_image = malloc(sizeof(int *) * imageRowSize);
    *columnSizes = malloc(sizeof(int *) * imageRowSize);
    *returnSize = imageRowSize;
    for (int i = 0; i < imageRowSize; i++) {
        new_image[i] = malloc(sizeof(int) * imageColSize);
        (*columnSizes)[i] = imageColSize;
        for (int j = 0; j < imageColSize; j++) {
            new_image[i][j] = image[i][j];
        }
    }
    row_size = imageRowSize;
    col_size = imageColSize;
    origin_color = image[sr][sc];
    new_color = newColor;
    if (origin_color != new_color)
        flood_r(new_image, sr, sc);
    return new_image;
}

int main() {
#if 0
    #define ROW_SIZE 3
    #define COL_SIZE 3
    int origin_images[][COL_SIZE] = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 2;
#else
    #define ROW_SIZE 2
    #define COL_SIZE 3
    int origin_images[][COL_SIZE] = {{0,0,0},{0,1,1}};
    int sr = 1;
    int sc = 1;
    int newColor = 1;
#endif

    int **images = malloc(sizeof(int *) * ROW_SIZE);
    for (int i = 0; i < ROW_SIZE; i++) {
        images[i] = malloc(sizeof(int) * COL_SIZE);
        for (int j = 0; j < COL_SIZE; j++) {
            images[i][j] = origin_images[i][j];
        }
    }
    int *new_column_size;
    int return_size;
    int **new_images = floodFill(images, ROW_SIZE, COL_SIZE, sr, sc, newColor, &new_column_size, &return_size);
    for (int i = 0; i < return_size; i++) {
        for (int j = 0; j < new_column_size[i]; j++) {
            printf("%d ", new_images[i][j]);
        }
        printf("\n");
    }
    return 0;
}