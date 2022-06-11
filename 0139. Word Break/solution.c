#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool *dp;
int *wordDictLen;

bool wordBreak_r(char* s, int slen, char** wordDict, int wordDictSize) {
    if (slen == 0)
        return true;
    if (dp[slen-1] == false)
        return false;
    for (int i = 0; i < wordDictSize; i++) {
        if (wordDictLen[i] == 0)
            wordDictLen[i] = strlen(wordDict[i]);
        if (slen >= wordDictLen[i] && strncmp(s, wordDict[i], wordDictLen[i]) == 0) {
            //printf("s=%s\n", s);
            if (wordBreak_r(s + wordDictLen[i], slen - wordDictLen[i], wordDict, wordDictSize))
                return true;
        }
    }
    dp[slen-1] = false;
    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int slen = strlen(s);
    bool result;
    dp = malloc(slen * sizeof(bool));
    wordDictLen = calloc(wordDictSize, sizeof(int));
    for (int i = 0; i < slen; i++) {
        dp[i] = true;
    }
    result = wordBreak_r(s, slen, wordDict, wordDictSize);
    free(wordDictLen);
    free(dp);
    return result;
}

int main() {
#if 0
    char *s = "applepenapple";
    char *wordDict[] = {"apple", "pen"};
    int wordDictSize = 2;
#elif 0
    char *s = "cars";
    char *wordDict[] = {"car","ca","rs"};
    int wordDictSize = 3;
#elif 1
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char *wordDict[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    int wordDictSize = 10;
#endif
    if (wordBreak(s, wordDict, wordDictSize))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}