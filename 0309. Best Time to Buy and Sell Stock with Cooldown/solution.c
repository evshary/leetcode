#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#if 1
int maxProfit(int* prices, int pricesSize){
    if (pricesSize <= 1) return 0;
    int buy, sell, rest;
    int pbuy = INT_MIN, psell = 0, prest = 0;
    for (int i = 0; i < pricesSize; i++) {
        buy = fmax(pbuy, prest - prices[i]);
        sell = fmax(psell, pbuy + prices[i]);
        rest = fmax(prest, fmax(psell, pbuy));
        pbuy = buy;
        psell = sell;
        prest = rest;
    }
    return sell;
}
#elif 1 // wrong answer while [6,1,3,2,4,7]
int maxProfit(int* prices, int pricesSize){
    if (prices == NULL || pricesSize < 1) return 0;
    int *d_table = (int *)malloc(sizeof(int) * pricesSize);
    if (!d_table) return -1;
    // init dynamic table
    d_table[0] = 0;
    if (pricesSize > 1)
        d_table[1] = fmax(prices[1] - prices[0], 0);
    if (pricesSize > 2)
        d_table[2] = fmax(fmax(prices[2]-prices[0], prices[2]-prices[1]), d_table[1]);
    // start to fill dynamic table
    for (int i = 3; i < pricesSize; i++) {
        d_table[i] = fmax(prices[i]-prices[i-1] + d_table[i-3], d_table[i-1]);
    }
    int result = d_table[pricesSize-1];
    free(d_table);
    return result;
}
#endif

int main() {
    //int prices[] = {1,2,3,0,2};
    //int prices[] = {6,1,3,2,4,7};
    int prices[] = {1,2,3,0,2};
    printf("result: %d\n", maxProfit(prices, sizeof(prices)/sizeof(int)));
    return 0;
}