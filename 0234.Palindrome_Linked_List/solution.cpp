/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#if 1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast, *last, *next;
        if (head == NULL) return true;
        slow = fast = head;
        last = NULL;
        next = slow->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow->next = last;
            last = slow;
            slow = next;
            next = next->next;
        }
        if (fast != NULL)
            slow = next;
        while (last != NULL || slow != NULL) {
            if (last->val != slow->val)
                return false;
            last = last->next;
            slow = slow->next;
        }
        return true;
    }
};
#elif 1  // Scan the linked list twice
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *ptr = head, *last, *next;
        int num = 0;
        if (head == NULL) return true;
        // count the total number
        while (ptr != NULL) {
            ptr = ptr->next;
            num++;
        }
        // reverse the first half
        ptr = head;
        last = NULL;
        next = ptr->next;
        for (int i = 0; i < num/2; i++) {
            ptr->next = last;
            last = ptr;
            ptr = next;
            next = next->next;
        }
        if (num % 2) ptr = ptr->next; // for odd number
        while (last != NULL || ptr != NULL) {
            if (last->val != ptr->val)
                return false;
            last = last->next;
            ptr = ptr->next;
        }
        return true;
    }
};
#endif