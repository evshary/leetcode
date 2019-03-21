#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIFF_CASE ('a'-'A')

char** letterCasePermutation(char* S, int* returnSize) {
    short bits = 0, tmp_bits;
    int letter_cnt = 0;
    *returnSize = 1;
    for (int i = 0; i < strlen(S); i++) {
        if (S[i] >= '0' && S[i] <= '9')
            continue;
        letter_cnt++;
        *returnSize <<= 1;
    }
    //printf("letter_cnt=%d, *returnSize=%d\n", letter_cnt, *returnSize);
    char **ret_array = malloc(sizeof(char *) * (*returnSize));
    char *tmp_S;
    for (int i = 0; i < (*returnSize); i++) {
        tmp_S = ret_array[i] = strdup(S);
        //printf("bits=%x\n", bits);
        tmp_bits = bits;
        for (int j = strlen(S)-1; j >= 0; j--) {
            if (tmp_S[j] >= '0' && tmp_S[j] <= '9')
                continue;
            if (tmp_bits & 0x01) {
                if (tmp_S[j] >= 'A' && tmp_S[j] <= 'Z') {
                    tmp_S[j] += DIFF_CASE;
                } else if (tmp_S[j] >= 'a' && tmp_S[j] <= 'z') {
                    tmp_S[j] -= DIFF_CASE;
                }
            }
            tmp_bits >>= 1;
        }
        bits++;
    }
    return ret_array;
}

int main() {
    int returnSize;
    char *S = "a1b2";
    char **ret_array = letterCasePermutation(S, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", ret_array[i]);
        free(ret_array[i]);
    }
    free(ret_array);
    return 0;
}