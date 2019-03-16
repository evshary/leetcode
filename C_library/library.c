#include <stdio.h>
#include <stdlib.h>
#include "library.h"

struct ListNode* genListFromArray(int *array, int arraySize) {
    if (array == NULL || arraySize == 0)
        return 0;
    struct ListNode *list = malloc(sizeof(struct ListNode));
    list->val = array[0];
    struct ListNode *ptr = list;
    for (int i = 1; i < arraySize; i++) {
        ptr->next = malloc(sizeof(struct ListNode));
        ptr = ptr->next;
        ptr->val = array[i];
        ptr->next = NULL;
    }
    return list;
}

void printList(struct ListNode* list) {
    while(list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

void freeList(struct ListNode* list) {
    struct ListNode *ptr = list;
    while(list != NULL) {
        ptr = list;
        list = list->next;
        free(ptr);
    }
}

static int Tree2Array(struct TreeNode* array[], int array_size) {
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

struct TreeNode* genTreeFromArray(int *array, int arraySize, int NULL_int) {
    if (arraySize == 0)
        return NULL;
    struct TreeNode *nodes_array[arraySize];
    int child_node_ptr = 1;

    for (int i = 0; i < arraySize; i++) {
        if (array[i] != NULL_int) {
            //printf("i=%d array[i]=%d\n", i, array[i]);
            nodes_array[i] = malloc(sizeof(struct TreeNode));
            nodes_array[i]->val = array[i];
            nodes_array[i]->left = nodes_array[i]->right = NULL;
        } else {
            //printf("i=%d null\n", i);
            nodes_array[i] = NULL;
        }
    }
    for (int i = 0; i < arraySize; i++) {
        if (nodes_array[i] != NULL) {
            //printf("nodes_array[%d]->val=%d\n", i, nodes_array[i]->val);
            nodes_array[i]->left = (child_node_ptr<arraySize)?nodes_array[child_node_ptr++]:NULL;
            nodes_array[i]->right = (child_node_ptr<arraySize)?nodes_array[child_node_ptr++]:NULL;
            //printf("child_node_ptr=%d\n", child_node_ptr);
        }
    }
    return nodes_array[0];
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