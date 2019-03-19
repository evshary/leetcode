#include <stdio.h>
#include <stdbool.h>
#include "../C_library/library.h"

#if 0 // it's good solution but I don't know why head can't be changed for C in leetcode.
bool hasCycle(struct ListNode *head) {
    struct ListNode *prevptr, *ptr = head;
    while(ptr != NULL) {
        if (ptr->next == head)
            return true;
        prevptr = ptr;
        ptr = ptr->next;
        prevptr->next = head;
    }
    return false;
}
#else
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    slow = fast = head;
    while(slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
#endif 

int main() {
    int array[] = {3,2,0,-4};
    struct ListNode *head = genListFromArray(array, ARRAY_SIZE(array));
    struct ListNode *ptr = head;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = head->next;
    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}