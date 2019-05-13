1. The algorithm is like following:
   a. find the longest incresing idx from rightside.
   b. Get the idx-1 as pivot. if there's no idx-1, go to e.
   c. Find the first number bigger than num[idx-1] from rightside.
   d. swap two number.
   e. reverse the subarray from idx to the end.
2. Ref: https://leetcode.com/problems/next-permutation/discuss/13994/Readable-code-without-confusing-ij-and-with-explanation