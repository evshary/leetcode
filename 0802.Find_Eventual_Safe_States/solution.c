#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getSafeNodes(int** graph, int graphRowSize, int *graphColSizes, int *safeNodes) {
    int changes = 0;
    int old_safeNodes;
    for (int i = 0; i < graphRowSize; i++) {
        old_safeNodes = safeNodes[i];
        safeNodes[i] = 1;
        for (int j = 0; j < graphColSizes[i]; j++) {
            if (graph[i][j] == i || safeNodes[graph[i][j]] != 1)
                safeNodes[i] = 0;
        }
        if (old_safeNodes != safeNodes[i])
            changes++;
        //printf("%d ", safeNodes[i]);
    }
    //printf("\n");
    if (changes != 0)
        getSafeNodes(graph, graphRowSize, graphColSizes, safeNodes);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* eventualSafeNodes(int** graph, int graphRowSize, int *graphColSizes, int* returnSize) {
    int safeNodes[graphRowSize];
    int *ret_array = malloc(graphRowSize * sizeof(int));
    memset(safeNodes, 0, sizeof(safeNodes));
    getSafeNodes(graph, graphRowSize, graphColSizes, safeNodes);
    *returnSize = 0;
    for (int i = 0; i < graphRowSize; i++) {
        if (safeNodes[i])
            ret_array[(*returnSize)++] = i;
    }
    return ret_array;
}

void initGraph(int row_size, int max_col_size, int origin_graph[row_size][max_col_size], int ***graph, int **col_size) {
    *col_size = malloc(row_size * sizeof(int));
    *graph = malloc(row_size * sizeof(int *));
    for (int i = 0; i < row_size; i++) {
        (*col_size)[i] = 0;
        for (int j = 0; origin_graph[i][j] != -1; j++)
            (*col_size)[i]++;
        if ((*col_size)[i] == 0) {
            (*graph)[i] = NULL;
            continue;
        }
        (*graph)[i] = malloc((*col_size)[i] * sizeof(int));
        for (int j = 0; j < (*col_size)[i]; j++) {
            (*graph)[i][j] = origin_graph[i][j];
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
    int *safe_node;
    int returnSize;
    int *col_size;
    int **graph;
#if 0
    #define MAX_COL_SIZE 3
    // [[1,2],[2,3],[5],[0],[5],[],[]]
    int origin_graph[][MAX_COL_SIZE] = {
        {1, 2, -1},
        {2, 3, -1},
        {5, -1},
        {0, -1},
        {5, -1},
        {-1},
        {-1}
    };
#else
    #define MAX_COL_SIZE 4
    // [[0],[2,3,4],[3,4],[0,4],[]]
    int origin_graph[][MAX_COL_SIZE] = {
        {0, -1},
        {2, 3, 4, -1},
        {3, 4, -1},
        {0, 4, -1},
        {-1},
    };
#endif
    int row_size = sizeof(origin_graph)/(sizeof(int)*MAX_COL_SIZE);
    initGraph(row_size, MAX_COL_SIZE, origin_graph, &graph, &col_size);
    printGraph(graph, row_size, col_size);
    safe_node = eventualSafeNodes(graph, row_size, col_size, &returnSize);
    printf("Answer = [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", safe_node[i]);
    }
    printf("]\n");
    return 0;
}