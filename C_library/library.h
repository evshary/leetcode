#ifndef _LIBRARY_C_
#define _LIBRARY_C_

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode* genListFromArray(int *array, int arraySize);
void printList(struct ListNode* list);
void freeList(struct ListNode* list);

struct TreeNode* genTreeFromArray(int *array, int arraySize, int NULL_int);
void printTreeNodes(struct TreeNode* tree);
void freeTreeNodes(struct TreeNode* tree);

#endif /*_LIBRARY_C_*/