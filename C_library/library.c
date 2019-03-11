#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int Tree2Array(struct TreeNode* array[], int array_size) {
    if (array == NULL)
        return 0;
    struct TreeNode* tree;
    int current_size = 1;
    for (int i = 0; i < current_size; i++) {
        //printf("i=%d current_size=%d\n", i, current_size);
        tree = array[i];
        if (tree == NULL)
            continue;
        //printf("val=%d\n", tree->val);
        array[current_size++] = tree->left;
        array[current_size++] = tree->right;
    }
    return current_size;
}

void printTreeNodes(struct TreeNode* tree) {
    int max_node_num = 20;
    struct TreeNode *nodes_array[max_node_num];
    nodes_array[0] = tree;
    int node_num = Tree2Array(nodes_array, max_node_num);
    for (int i = 0; i < node_num; i++) {
        if (nodes_array[i] != NULL)
            printf("%d ", nodes_array[i]->val);
        else
            printf("null ");
    }
    printf("\n");
}

void freeTreeNodes(struct TreeNode* tree) {
    if (tree != NULL) {
        freeTreeNodes(tree->left);
        freeTreeNodes(tree->right);
        free(tree);
    }
    return;
}