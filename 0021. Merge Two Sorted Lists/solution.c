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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *list = NULL, *tmp_list;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            if (list == NULL) {
                list = l1;
                tmp_list = list;
            } else {
                tmp_list->next = l1;
                tmp_list = l1;
            }
            l1 = l1->next;
        } else {
            if (list == NULL) {
                list = l2;
                tmp_list = list;
            } else {
                tmp_list->next = l2;
                tmp_list = l2;
            }
            l2 = l2->next;
        }
    }
    if (l1 != NULL)
        tmp_list->next = l1;
    else if (l2 != NULL)
        tmp_list->next = l2;
    return list;
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
    struct ListNode *l1, *l2, *mlist;
    int node1[] = {1,2,4,5};
    int node2[] = {1,3,4};
    l1 = allocListNode(node1, sizeof(node1)/sizeof(int));
    l2 = allocListNode(node2, sizeof(node2)/sizeof(int));
    printListNode(l1);
    printListNode(l2);
    mlist = mergeTwoLists(l1, l2);
    printListNode(mlist);
    return 0;
}