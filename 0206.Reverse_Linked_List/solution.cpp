 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

#if 1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *prev = NULL, *cur = head, *next = head->next;
        while(next != NULL) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
};
#else // recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *next = head->next;
        ListNode *ret = reverseList(next);
        head->next = NULL;
        next->next = head;
        return ret;
    }
};
#endif