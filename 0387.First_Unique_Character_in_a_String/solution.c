#include <stdio.h>
#include <string.h>

int firstUniqChar(char * s){
    int tables[26] = {0};
    int s_size = strlen(s);
    for (int i = 0; i < s_size; i++) {
        tables[s[i]-'a']++;
    }
    for (int i = 0; i < s_size; i++) {
        if (tables[s[i]-'a'] == 1) return i;
    }
    return -1;
}

int main() {
    char *s = "leetcode";
    printf("result: %d\n", firstUniqChar(s));
    return 0;
}