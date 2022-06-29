#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int slen = strlen(s);
    int tlen = strlen(t);
    if (slen != tlen)
        return false;
    int hash_tables[2][26] = {0};
    for (int i = 0; i < slen; i++) {
        hash_tables[0][s[i] - 'a']++;
        hash_tables[1][t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (hash_tables[0][i] != hash_tables[1][i])
            return false;
    }
    return true;
}

int main() {
#if 0
    char *s = "anagram";
    char *t = "nagaram";
#elif 1
    char *s = "rat", *t = "car";
#endif
    if (isAnagram(s, t))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}