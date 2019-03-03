1. The init of variable-length array is not easy.
2. Understand the difference of sizeof(int) and sizeof(int *).
3. Make sure you understand the difference between `char **` and `char [][]`.
4. In C99, it's able to pass parameter like that `void array_function(int m, int n, float a[m][n])`.
   - Ref: https://stackoverflow.com/questions/6862813/c-passing-a-2d-array-as-a-function-argument
5. Consider the case which point to itself, and add exception handling.
6. My result:
   - Runtime: 204 ms, faster than 100.00% of C online submissions for Find Eventual Safe States.
   - Memory Usage: 20.4 MB, less than 100.00% of C online submissions for Find Eventual Safe States.