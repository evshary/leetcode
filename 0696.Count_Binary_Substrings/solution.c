#include <stdio.h>
#include <string.h>
#include <math.h>

int countBinarySubstrings(char * s){
    int result = 0;
    int cnt[2] = {0};
    int cnt_idx = 1;
    int cur_ch = s[0];
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == cur_ch) {
            cnt[cnt_idx%2]++;
        } else {
            result += fmin(cnt[cnt_idx%2],cnt[(cnt_idx-1)%2]);
            cnt_idx++;
            cnt[cnt_idx%2] = 1;
            cur_ch = s[i];
        }
    }
    return result + fmin(cnt[cnt_idx%2],cnt[(cnt_idx-1)%2]);
}

int main() {
#if 1
    char *s = "00110011";
#elif 1
    char *s = "00110";
#endif
    printf("result=%d\n", countBinarySubstrings(s));
    return 0;
}