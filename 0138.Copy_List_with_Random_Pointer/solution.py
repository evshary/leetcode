# Ref: https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43485/Clear-and-short-python-O(2n)-and-O(n)-solution
# fist
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        dicts = {}
        ptr = head
        while ptr:
            dicts[ptr] = Node(ptr.val, 0, 0)
            ptr = ptr.next
        ptr = head
        while ptr:
            dicts[ptr].next = dicts.get(ptr.next, None)
            dicts[ptr].random = dicts.get(ptr.random, None)
            ptr = ptr.next
        return dicts.get(head, None)

# second
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        dicts = collections.defaultdict(lambda: Node(0, 0, 0))
        dicts[None] = None
        ptr = head
        while ptr:
            dicts[ptr].val = ptr.val
            dicts[ptr].next = dicts[ptr.next]
            dicts[ptr].random = dicts[ptr.random]
            ptr = ptr.next
        return dicts[head]