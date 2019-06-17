#if 1 // without shifting for 32 times
int hammingWeight(uint32_t n) {
    int count = 0;
    while(n) {
        count++;
        n = n & (n-1); // drop the least 1 bit
    }
    return count;
}
#else
int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (n & 0x01) count++;
        n >>= 1;
    }
    return count;
}
#endif