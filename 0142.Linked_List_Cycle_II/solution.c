#include "../C_library/library.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct ListNode *detectCycle(struct ListNode *head) {
    bool isCyclic = false;
    struct ListNode *fast, *slow, *cycle_begin;
    cycle_begin = fast = slow = head;
    while(slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            isCyclic = true;
            break;
        }
    }
    if (isCyclic) {
        while(cycle_begin != slow) {
            cycle_begin = cycle_begin->next;
            slow = slow->next;
        }
        return cycle_begin;
    } else
        return NULL;
}

int main() {
    int array[] = {3,2,0,-4};
    struct ListNode *head = genListFromArray(array, ARRAY_SIZE(array));
    struct ListNode *ptr = head;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next = head->next;
    struct ListNode *ans = detectCycle(head);
    printf("ans->val=%d\n", ans->val);
    return 0;
}