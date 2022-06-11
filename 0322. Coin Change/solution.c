#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#if 1
int coinChange(int* coins, int coinsSize, int amount) {
    if (coinsSize == 0) return -1;
    if (amount == 0) return 0;
    int result;
    int *d_table = (int *)malloc((amount+1) * sizeof(int));
    if (d_table == NULL) return -1;
    d_table[0] = 0;
    for (int i = 1; i <= amount; i++) {
        d_table[i] = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i >= coins[j] && d_table[i-coins[j]] != INT_MAX) {
                d_table[i] = fmin(d_table[i], d_table[i-coins[j]]+1);
            }
        }
    }
    if (d_table[amount] == INT_MAX)
        result = -1;
    else
        result = d_table[amount];
    free(d_table);
    return result;
}
#elif 1 // this way don't work, since in the case of [511,510,1] amount=1020, we get 511+1*509, but correct is 510+510
int coinChange_r(int* coins, int coinsSize, int amount) {
    int cnt_1 = -1;
    int val, ret;
    // find out the count of 1st idx in coins >= amount
    do {
        val = ++cnt_1 * coins[0];
    } while(val < amount);
    if (val == amount) return cnt_1;
    if (coinsSize > 1) {
        while (--cnt_1 >= 0) {
            ret = coinChange_r(coins+1, coinsSize-1, amount-coins[0]*cnt_1);
            if (ret != -1) return cnt_1+ret;
        }
    }
    return -1;
}

int compare_func(const void *left, const void *right) {
    return (*(int *)right - *(int *)left);
}

int coinChange(int* coins, int coinsSize, int amount){
    if (coinsSize == 0) return -1;
    // sort the coin from big to small
    qsort(coins, coinsSize, sizeof(int), compare_func);
    // do divide and conquer and find out coins start with certain ammount
    return coinChange_r(coins, coinsSize, amount);
}
#endif

int main() {
#if 1
    int coins[] = {1,2,5};
    int amount = 11;
#elif 1
    int coins[] = {186,419,83,408};
    int amount = 6249;
#endif
    printf("result:%d\n", coinChange(coins, sizeof(coins)/sizeof(int), amount));
    return 0;
}