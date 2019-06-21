#include <stdio.h>
#include <string.h>

void reverseString(char* s, int sSize){
    for (int lptr = 0, rptr = sSize-1; lptr < rptr; lptr++, rptr--) {
        s[lptr] ^= s[rptr];
        s[rptr] = s[lptr] ^ s[rptr];
        s[lptr] ^= s[rptr];
    }
}

int main() {
    char str[] = "hello";
    reverseString(str, strlen(str));
    printf("result: %s\n", str);
    return 0;
}