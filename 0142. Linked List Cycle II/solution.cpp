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
    ListNode *detectCycle(ListNode *head) {
#if 1
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                break;
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr; // there is no cycle
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
#else
        unordered_map<ListNode *,bool> hash;
        ListNode *node = head;
        while (node != nullptr) {
            if (hash.find(node) != hash.end()) {
                return node;
            }
            hash[node] = true;
            node = node->next;
        }
        return nullptr;
#endif
    }
};