#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BRUTE_FORCE 0
#define DYNAMIC_PROGRAMMING 1
#if BRUTE_FORCE
char* longestPalindrome(char* s) {
    int s_len = strlen(s);
    int tmp_i, tmp_j;
    if (s_len == 0)
        return "";
    char *result = malloc(s_len+1);
    memset(result, 0, s_len+1);
    for (int i = 0; i < s_len; i++) {
        for (int j = i; j < s_len; j++) {
            tmp_i = i, tmp_j = j;
            while(tmp_j > tmp_i) {
                if (s[tmp_j] != s[tmp_i])
                    break;
                tmp_j--;
                tmp_i++;
            }
            if (tmp_j <= tmp_i) {
                if ((j - i + 1) > strlen(result)) {
                    //printf("j=%d i=%d\n", j, i);
                    strncpy(result, &s[i], j-i+1);
                    result[j-i+1] = 0;
                } 
            }
                
        }
    }
    return result;
}
#endif
#if DYNAMIC_PROGRAMMING
char* longestPalindrome(char* s) {
    char *result;
    int s_len = strlen(s);
    if (s_len == 0)
        return "";
    bool dp_table[s_len][s_len];
    // init dp table
    for (int i = 0; i < s_len; i++) {
        for (int j = 0; j < s_len; j++) {
            dp_table[i][j] = false;
        }
    }
    // init dp_table[i][i] = true and dp_table[i][i+1] = true while char is the same
    for (int i = 0; i < s_len; i++) {
        dp_table[i][i] = true;
        if (i < s_len - 1 && s[i] == s[i+1])
            dp_table[i][i+1] = true;
    }
    // run dp table
    for (int i = s_len - 3; i >= 0; i--) {
        for (int j = i + 2; j < s_len; j++) {
            if (dp_table[i+1][j-1] && s[i] == s[j])
                dp_table[i][j] = true;
        }
    }
    // get the max length
    int max_len = 0;
    int start = 0;
    for (int i = 0; i < s_len; i++) {
        for (int j = i; j < s_len; j++) {
            if (dp_table[i][j] && max_len < (j-i+1)) {
                max_len = j - i + 1;
                start = i;
            }
        }
    }
    result = malloc(max_len + 1);
    strncpy(result, &s[start], max_len);
    result[max_len] = 0;
    return result;
}
#endif

int main() {
    char *input = "babad";
    printf("%s\n", longestPalindrome(input));
    return 0;
}