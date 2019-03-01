#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *ptr, *next, *prev;
    if (head == NULL)
        return NULL;
    ptr = head;
    prev = NULL;
    while (ptr != NULL && ptr->next != NULL) {
        /* reserve the node of next 2 node */
        next = ptr->next->next;
        /* swap the node */
        if (prev != NULL) {
            prev->next = ptr->next;
        } else {
            /* first node => adjust the head */
            head = ptr->next;
        }
        ptr->next->next = ptr;
        ptr->next = next;
        /* update prev */
        prev = ptr;
        /* change to next 2 node */
        ptr = next;
    }
    return head;
}

void printListNode(struct ListNode* list) {
    while (list->next) {
        printf("%d->", list->val);
        list = list->next;
    }
    printf("%d\n", list->val);
}

struct ListNode* allocListNode(int *node, int node_num) {
    struct ListNode *list, *ptr;
    int idx = 0;
    list = malloc(sizeof(struct ListNode));
    list->val = node[idx];
    list->next = NULL;
    node_num--;
    idx++;
    ptr = list;
    while (node_num--) {
        ptr->next = malloc(sizeof(struct ListNode));
        ptr = ptr->next;
        ptr->val = node[idx];
        idx++;
    }
    ptr->next = NULL;
    return list;
}

int main()
{
    struct ListNode *list;
    int node[] = {1,2,3,4};
    list = allocListNode(node, sizeof(node)/sizeof(int));
    printListNode(list);
    list = swapPairs(list);
    printListNode(list);
    return 0;
}