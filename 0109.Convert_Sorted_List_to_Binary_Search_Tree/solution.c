#include "../C_library/library.h"
#include <stdlib.h>
#include <stdio.h>

struct TreeNode* sortedListToBST_r(struct ListNode **head, int num) {
    if (head == NULL || num == 0)
        return NULL;
    int medium = num / 2;
    struct TreeNode *left_node = sortedListToBST_r(head, medium);
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = (*head)->val;
    node->left = left_node;
    *head = (*head)->next;
    struct TreeNode *right_node = sortedListToBST_r(head, num - medium - 1);
    node->right = right_node;
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct ListNode *ptr = head;
    int total_num = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        total_num++;
    }
    return sortedListToBST_r(&head, total_num);
}

int main() {
    int array[] = {-10,-3,0,5,9};
    struct ListNode *list = genListFromArray(array, sizeof(array)/sizeof(array[0]));
    printList(list);
    struct TreeNode *root = sortedListToBST(list);
    printTreeNodes(root);
    freeList(list);
    return 0;
}