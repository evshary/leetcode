#include "../C_library/library.h"
#include <stdlib.h>

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *ptr = head, *prev;
    while(head != NULL) {
        if (ptr->val != val)
            break;
        head = head->next;
        free(ptr);
        ptr = head;
    }
    if (head == NULL)
        return head;
    prev = head;
    ptr = head->next;
    while(ptr) {
        if (ptr->val == val) {
            prev->next = ptr->next;
            free(ptr);
            ptr = prev->next;
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}

int main() {
    int array[] = {1,2,6,3,4,5,6};
    int val = 6;
    struct ListNode *head = genListFromArray(array, ARRAY_SIZE(array));
    head = removeElements(head, 6);
    printList(head);
    freeList(head);
    return 0;
}