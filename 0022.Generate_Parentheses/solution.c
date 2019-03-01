#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **result;
int result_size = 0;
int used_size = 0;;

inline void saveResult(char *str) {
    if (used_size == result_size) {
        result_size++;
        result = (char **)realloc(result, sizeof(char *) * result_size);
    }
    result[used_size] = str;
    used_size++;
}

void genP_r(int lcount, int rcount, char *str) {
    char *param_str = malloc(strlen(str)+2);
    strcpy(param_str, str);
    param_str[strlen(str)+1] = 0;
    if (lcount == 0 && rcount == 0) {
        param_str[strlen(str)] = 0;
        saveResult(param_str);
        return;
    }
    if (lcount > 0) {
        param_str[strlen(str)] = '(';
        genP_r(lcount -1, rcount, param_str);
    }
    if (rcount > lcount) {
        param_str[strlen(str)] = ')';
        genP_r(lcount, rcount - 1, param_str);
    }
    free(param_str);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    result = (char **)malloc(sizeof(char *) * 1);
    result_size = 1;
    used_size = 0;
    genP_r(n, n, "");
    *returnSize = used_size;
    return result;
}

int main()
{
    int ret_size;
    char **ret_result;
    ret_result = generateParenthesis(3, &ret_size);
    for (int i = 0; i < ret_size; i++) {
        printf("%s\r\n", ret_result[i]);
    }
    return 0;
}