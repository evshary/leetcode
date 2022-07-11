/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
	void reverseNode(ListNode **start, ListNode **end) {
		ListNode *prev = nullptr, *cur = *start, *next;
        ListNode *endnode = (*end)->next;
		while (cur != endnode) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		swap(*start, *end);
	}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *prev, *start, *end, *next;
        prev = dummy;
        start = end = head;
        while (end != nullptr) {
        	int idx = k - 1;
        	while (idx != 0 && end != nullptr) {
        		end = end->next;
        		idx--;
        	}
        	if (idx == 0 && end != nullptr) {
        		next = end->next;
        		reverseNode(&start, &end);
        		prev->next = start;
        		end->next = next;
                // move to next group
                prev = end;
            	start = end = next;
        	}
        }
        ListNode *ans = dummy->next;
        delete(dummy);
        return ans;
    }
};
