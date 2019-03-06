#include <stdio.h>
#define BRUTE_FORCE 0
#define DP 1

#if DP
#define max(x,y) ((x)>(y))?(x):(y)
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int min_price_idx = 0;
    for (int i=0; i < pricesSize; i++) {
        if (prices[i] < prices[min_price_idx])
            min_price_idx = i;
        else
            profit = max(profit, prices[i] - prices[min_price_idx]);
    }
    return profit;
}
#endif /*DP*/

#if BRUTE_FORCE
#define max(x,y) ((x)>(y))?(x):(y)
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i; j < pricesSize; j++) {
            profit = max(profit, prices[j] - prices[i]);
        }
    }
    return profit;
}
#endif /*BRUTE_FORCE*/

int main() {
    int prices[] = {7,1,5,3,6,4};
    printf("max profit=%d\n", maxProfit(prices, sizeof(prices)/sizeof(prices[0])));
    return 0;
}