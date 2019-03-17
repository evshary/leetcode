#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    if (N == 0)
        return -1;
    bool adj_matrix[N][N];
    bool judge_candicate[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj_matrix[i][j] = false;
        }
        judge_candicate[i] = true;
    }
    for (int i = 0; i < trustRowSize; i++) {
        adj_matrix[trust[i][0]-1][trust[i][1]-1] = true;
        judge_candicate[trust[i][0]-1] = false;
    }
    for (int i = 0; i < N; i++) {
        if (judge_candicate[i] == false)
            continue;
        int j;
        for (j = 0; j < N; j++) {
            //printf("i=%d, j=%d\n", i, j);
            if (i == j)
                continue;
            if (adj_matrix[j][i] == false)
                break;
        }
        if (j == N)
            return i+1;
    }
    return -1;
}

int main() {
    #define COL_SIZE 2
#if 0
    int N = 2;
    int ori_trust[][COL_SIZE] = {{1,2}};
#endif
#if 0
    int N = 3;
    int ori_trust[][COL_SIZE] = {{1,3},{2,3}};
#endif
#if 1
    int N = 3;
    int ori_trust[][COL_SIZE] = {{1,3},{2,3},{3,1}};
#endif
    int row_size = sizeof(ori_trust)/sizeof(ori_trust[0]);
    int *col_size = malloc(sizeof(int) * row_size);
    int **trust = malloc(sizeof(int *) * row_size);
    for (int i = 0; i < row_size; i++) {
        col_size[i] = COL_SIZE;
        trust[i] = malloc(sizeof(int) * col_size[i]);
        for (int j = 0; j < col_size[i]; j++) {
            trust[i][j] = ori_trust[i][j];
        }
    }
    printf("findJudge=%d\n", findJudge(N, trust, row_size, col_size));
    free(col_size);
    for (int i = 0; i < row_size; i++)
        free(trust[i]);
    free(trust);
    return 0;
}