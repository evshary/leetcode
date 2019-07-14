#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char * addBinary(char * a, char * b){
    int alen = strlen(a)-1;
    int blen = strlen(b)-1;
    char *ret = malloc(fmax(alen, blen)+3); // why 3? -1 and carry and '\0'
    memset(ret, 0, fmax(alen, blen)+3);
    int cur_pos = 0;
    int carry = 0;
    int result;
    for (; alen >= 0 || blen >= 0 || carry != 0; alen--, blen--) {
        result = ((alen >= 0)?a[alen]-'0':0) + 
                 ((blen >= 0)?b[blen]-'0':0) + carry;
        ret[cur_pos++] = (result % 2) + '0';
        carry = result / 2;
    }
    cur_pos--;
    for (int i = 0; i < cur_pos; i++, cur_pos--) {
        int tmp = ret[i];
        ret[i] = ret[cur_pos];
        ret[cur_pos] = tmp;
    }
    return ret;
}

int main() {
#if 0
    char *a = "11";
    char *b = "1";
#elif 1
    char *a = "1010";
    char *b = "1011";
#endif
    char *result = addBinary(a, b);
    printf("answer: %s\n", result);
    free(result);
    return 0;
}