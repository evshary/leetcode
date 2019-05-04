1. The problems is obvious to use stack because we want to compare from the last part of the linked list.
2. However we want to have space complexity O(1). Therefore we should get the size first and start with the same size to compare linked list A and B.
3. While run to the end of listA, then go to listB. For A, it runs a+c+b, and for B, it runs b+c+a. a is the length from start of listA to intersection, and b is the same for listB. c is the length from intersection to the end.
4. Ref: http://www.ciaoshen.com/algorithm/leetcode/2017/06/08/leetcode-intersection-of-two-linked-list.html