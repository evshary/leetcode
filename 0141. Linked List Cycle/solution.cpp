/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast != nullptr && fast->next != nullptr)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
        }
        return true;
    }
};