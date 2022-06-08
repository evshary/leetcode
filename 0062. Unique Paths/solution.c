#include <stdio.h>
#include <string.h>

#define RECURSION 1
#define FORMULA   0

#if RECURSION
int uniquePaths_r(int i, int j, int m, int n, int dp_path[m][n]) {
    //printf("i=%d j=%d dp_path[i][j]=%d\n", i, j, dp_path[i][j]);
    if (dp_path[i][j] == -1)
        dp_path[i][j] = uniquePaths_r(i-1, j, m, n, dp_path) + uniquePaths_r(i, j-1, m, n, dp_path);
    return dp_path[i][j];
}

int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    int dp_path[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dp_path[i][j] = -1;
    for (int i = 0; i < m; i++)
        dp_path[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp_path[0][j] = 1;
    return uniquePaths_r(m-1, n-1, m, n, dp_path);
}
#endif /*RECURSION*/

#if FORMUAL
int uniquePaths(int m, int n) {
    if (m-- == 0 || n-- == 0) return 0;
    if (m < n) { // make sure m is always big
        m ^= n;
        n = m ^ n;
        m ^= n;
    }
    long long return_val = 1;
    //printf("m=%d, n=%d\n", m, n);
    for (int i = m+1, j = 1; i <= m + n; i++, j++) {
        return_val *= i;
        return_val /= j;
    }
    return return_val;
}
#endif /*FORMULA*/

int main () {
    printf("uniquePaths=%d\n", uniquePaths(7,3));
    printf("uniquePaths=%d\n", uniquePaths(10,10));
    printf("uniquePaths=%d\n", uniquePaths(51,9));
    return 0;
}