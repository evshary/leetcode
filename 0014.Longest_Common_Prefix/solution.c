#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0)
        return "";
    char *ret_str = strdup(strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int minlength = fmin(strlen(ret_str), strlen(strs[i]));
        int j;
        for (j = 0; j < minlength; j++) {
            if (ret_str[j] != strs[i][j]) {
                break;
            }
        }
        ret_str[j] = 0;
    }
    return ret_str;
}

int main() {
#if 0
    char *strs[] = {
        "flower","flow","flight"
    };
    int strsSize = 3;
#else
    char *strs[] = {"aa", "a"};
    int strsSize = 1;
#endif
    char *ret_str = longestCommonPrefix(strs, strsSize);
    printf("%s\n", ret_str);
    free(ret_str);
    return 0;
}