#include <stdio.h>

#define MAX_NUM ((1<<30)-1+(1<<30))
#define MIN_NUM (-1<<31)

int reverse(int x) {
    int ret_num = 0;
    while(x) {
        if (MAX_NUM/10 < ret_num || MIN_NUM/10 > ret_num ||
            ((MAX_NUM/10 == ret_num) && (MAX_NUM%10 < x%10)) ||
            ((MIN_NUM/10 == ret_num) && (MIN_NUM%10 > x%10)) ) {
            return 0;
        }
        ret_num *= 10;
        ret_num += x % 10;
        x /= 10;
    }
    return ret_num;
}

int main()
{
    printf("MAX=%d, MIN=%d\n", MAX_NUM, MIN_NUM);
    printf("Answer=%d\n", reverse(123));
    printf("Answer=%d\n", reverse(1534236469));
    printf("Answer=%d\n", reverse(-2147483648));
    printf("Answer=%d\n", reverse(1463847412));
    return 0;
}