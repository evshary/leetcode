/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *ret, *tmp, *last;
    unsigned int value;
    char carry = 0;
    ret = last = NULL;

    do
    {
        tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        value = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0) + carry;
        carry = 0;
        if (value >= 10)
        {
            value -= 10;
            carry = 1;
        }
        tmp->val = value;
        tmp->next = NULL;
        if (last != NULL)
            last->next = tmp;
        else
            ret = tmp;
        last = tmp;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    while (l1 || l2 || carry);

    return ret;
}

struct ListNode *changeArr2List(unsigned char *arr, int ar_size)
{
    struct ListNode *list, *last, *ret;

    last = NULL;
    for (int i = 0; i < ar_size; i++, arr++)
    {
        list = (struct ListNode *)malloc(sizeof(struct ListNode));
        list->val = *arr;
        list->next = NULL;
        if (last != NULL)
            last->next = list;
        else
            ret = list;
        last = list;
    }

    return ret;
}

void FreeList(struct ListNode *list)
{
    struct ListNode *ptr;
    ptr = list;
    while (ptr != NULL)
    {
        ptr = list->next;
        free(list);
        list = ptr;
    }
}

void PrintList(struct ListNode *list)
{
    printf("list=");
    while (list != NULL)
    {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\r\n");
}

int main()
{
    struct ListNode *l1, *l2, *answer;
    unsigned char arr1[] = {9};
    unsigned char arr2[] = {1, 9, 9, 9, 9, 9, 9, 9, 9, 9};

    l1 = changeArr2List(arr1, sizeof(arr1));
    l2 = changeArr2List(arr2, sizeof(arr2));
    printf("List1: ");
    PrintList(l1);
    printf("List2: ");
    PrintList(l2);
    answer = addTwoNumbers(l1, l2);
    printf("Answer: ");
    PrintList(answer);
    FreeList(l1);
    FreeList(l2);
    FreeList(answer);
    return 0;
}