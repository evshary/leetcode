#include <iostream>
#include "../C_library/library.h"
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        struct ListNode *prev, *ptr = head;
        while(ptr) {
            if (ptr->val != val)
                break;
            head = ptr->next;
            delete ptr;
            ptr = head;
        }
        if (head != 0) {
            ptr = head->next;
            prev = head;
            while(ptr) {
                if (ptr->val == val) {
                    prev->next = ptr->next;
                    delete ptr;
                    ptr = prev->next;
                } else {
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
        }
        return head;
    }
};

int main() {
    int array[] = {1,2,6,3,4,5,6};
    int val = 6;
    struct ListNode *head, *ptr, *prev;
    for (int i = 0; i < ARRAY_SIZE(array); i++) {
        if (i == 0) {
            head = new ListNode;
            head->val = array[i];
            head->next = 0;
            ptr = head;
        } else {
            ptr->next = new ListNode;
            ptr = ptr->next;
            ptr->val = array[i];
            ptr->next = 0;
        }
    }
    Solution solution;
    head = solution.removeElements(head, 6);
    ptr = head;
    while (ptr != 0) {
        cout << ptr->val << endl;
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
    return 0;
}