#include <stdio.h>

int hammingDistance(int x, int y){
    int distance = 0;
    for (int z = x^y; z != 0; z >>= 1)
        if ((z & 0x1) == 1) distance++;
    return distance;
}

int main() {
    printf("distance: %d\n", hammingDistance(1,8));
    return 0;
}