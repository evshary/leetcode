1. Althought using stack is a good way, I can't think of it at the first time.
2. Another way is to save the higher number in the left/right of the current number. Then calculate it.
3. Remember that we can use the number calculated before, but can't always rely on it. For example [1,4,3,2], the right_higher will be [x,0,0,0] while calucating x. We need to go through 4, 3, 2 to get x=3.
4. If you want to use stack, remember to add 0 in the end of array to force calculating the result.