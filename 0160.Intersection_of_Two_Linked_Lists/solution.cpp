#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

#if 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *ptr, *ptrA, *ptrB;
        for (ptr = headA; ptr != NULL; ptr=ptr->next) {
            ptrA = ptr;
            lenA++;
        }
        for (ptr = headB; ptr != NULL; ptr=ptr->next) {
            ptrB = ptr;
            lenB++;
        }
        /* No intersection */
        if (ptrA != ptrB)
            return NULL;
        /* Start from the same size */
        while (lenA != lenB) {
            if (lenA > lenB) {
                headA = headA->next;
                lenA--;
            } else if (lenA < lenB) {
                headB = headB->next;
                lenB--;
            }
        }
        /* Start and find the intersection */
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
#else // Using stack
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> sa, sb;
        ListNode *ptr, *result = NULL;
        for (ptr = headA; ptr != NULL; ptr=ptr->next)
            sa.push(ptr);
        for (ptr = headB; ptr != NULL; ptr=ptr->next)
            sb.push(ptr);
        while(!sa.empty() && !sb.empty() && sa.top() == sb.top()) {
            result = sa.top();
            sa.pop();
            sb.pop();
        }
        return result;
    }
};
#endif