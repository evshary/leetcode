#include <stdio.h>

#define bool int
#define true 1
#define false 0

bool isPalindrome(int x) {
    int idx = 0, tmp_idx = 0;
    char arr[10] = {0};
    
    if (x < 0) return false;
    else if (x == 0) return true;
    while (x) {
        arr[idx++] = x % 10;
        x /= 10;
    }
    idx--;
    while (1) {
        if (arr[tmp_idx++] != arr[idx--])
            return false;
        if (idx <= tmp_idx)
            return true;
    }
}

int main()
{
    printf("Answer=%d\n", isPalindrome(121));
    printf("Answer=%d\n", isPalindrome(-121));
    printf("Answer=%d\n", isPalindrome(591195));
    printf("Answer=%d\n", isPalindrome(0));
    return 0;
}