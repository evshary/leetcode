#include <stdio.h>
#include <string.h>

#define INRANGE(num1,num2) (num1 == '1' || (num1 == '2' && num2 <= '6'))

int numDecodings(char * s){
    int len = strlen(s);
    if (len == 0 || s[0] == '0' ) return 0;
    char last_num = s[0], cur_num;
    int dp_nums[3] = {1};
    for (int i = 1; i < len; i++) {
        cur_num = s[i];
        if (cur_num != '0' && INRANGE(last_num, cur_num)) {
            dp_nums[i%3] = dp_nums[(i-1)%3] + ((i>=2)?dp_nums[(i-2)%3]:1);
        } else if (cur_num != '0' && !INRANGE(last_num, cur_num)) {
            dp_nums[i%3] = dp_nums[(i-1)%3];
        } else if (cur_num == '0' && INRANGE(last_num, cur_num)) {
            dp_nums[i%3] = ((i>=2)?dp_nums[(i-2)%3]:1);
        } else {
            return 0;
        }
        last_num = cur_num;
    }
    return dp_nums[(len-1)%3];
}

int main() {
    //char *s = "111222";
    //char *s = "101010101";
    //char *s = "00"; // I think this is ridiculous, but the test case includes zero.
    //char *s = "100";
    //char *s = "011";
    char *s = "10";
    printf("result=%d\n", numDecodings(s));
    return 0;
}