#include <stdlib.h>
#include <stdio.h>
#include "../C_library/library.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *ptr = head;
    struct ListNode *remove_prevptr = head;
    struct ListNode *remove_ptr = head;
    int count = 0;
    while (ptr != NULL) {
        if (count == n+1) {
            remove_prevptr = remove_prevptr->next;
            remove_ptr = remove_ptr->next;
        } else {
            if (count == n)
                remove_ptr = remove_ptr->next;
            count++;
        }
        ptr = ptr->next;
    }
    if (remove_ptr == head) {
        head = head->next;
    } else {
        remove_prevptr->next = remove_ptr->next;
    }
    free(remove_ptr);
    return head;
}

int main() {
#if 0
    int linkedlist[] = {1, 2, 3, 4, 5};
    int n = 2;
#elif 1
    int linkedlist[] = {1, 2, 3, 4, 5};
    int n = 5;
#else
    int linkedlist[] = {1};
    int n = 1;
#endif
    struct ListNode *head = genListFromArray(linkedlist, ARRAY_SIZE(linkedlist));
    struct ListNode *result = removeNthFromEnd(head, n);
    printList(result);
    return 0;
}