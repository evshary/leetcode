#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int climbStairs_r(int n, int *save_array) {
    if (save_array[n] == -1)
        save_array[n] = climbStairs_r(n-1, save_array) + climbStairs_r(n-2, save_array);
    return save_array[n];
}

int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int save_array[n+1];
    for (int i = 0; i <= n; i++)
        save_array[i] = -1;
    save_array[1] = 1;
    save_array[2] = 2;
    return climbStairs_r(n, save_array);
}

int main () {
    int n = 10;
    printf("climbStairs=%d\n", climbStairs(n));
    return 0;
}