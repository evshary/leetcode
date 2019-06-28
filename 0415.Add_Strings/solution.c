#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#if 1
#define STR_SIZE 5100
char * addStrings(char * num1, char * num2) {
    int len1 = strlen(num1)-1;
    int len2 = strlen(num2)-1;
    int digit1, digit2, carrier = 0;
    int str_len = 0;
    char *str = malloc(fmax(len1,len2)+3);
    memset(str, 0, fmax(len1,len2)+3);
    // add two digits
    for (; len1 >= 0 || len2 >= 0; len1--, len2--, str_len++) {
        digit1 = (len1 < 0)? 0 : (num1[len1] - '0');
        digit2 = (len2 < 0)? 0 : (num2[len2] - '0');
        str[str_len] = ((digit1 + digit2 + carrier) % 10) + '0';
        carrier = (digit1 + digit2 + carrier)/10;
    }
    if (carrier) str[str_len++] = carrier + '0'; // handling carrier
    // swap the string
    for (int i = 0, j = str_len-1; i < j; i++, j--) {
        str[i] ^= str[j];
        str[j] = str[i] ^ str[j];
        str[i] ^= str[j];
    }
    return str;
}
#else // only applied to small number
char * addStrings(char * num1, char * num2) {
    int len1 = strlen(num1)-1;
    int len2 = strlen(num2)-1;
    int result = 0;
    int digit1, digit2, multiply = 1;
    for (; len1 >= 0 || len2 >= 0; len1--, len2--, multiply*=10) {
        digit1 = (len1 < 0)? 0 : (num1[len1] - '0');
        digit2 = (len2 < 0)? 0 : (num2[len2] - '0');
        result += (digit1 + digit2) * multiply;
        //printf("%d + %d = %d\n", digit1, digit2, result);
    }
    int str_len = 1;
    int large_num = 10;
    while(result / large_num != 0) {
        large_num *= 10;
        str_len++;
    }
    //printf("str_len = %d\n", str_len);
    char *str = malloc(str_len+1);
    str[str_len] = '\0';
    for (int i = str_len-1; i >= 0; i--) {
        str[i] = (result % 10) + '0';
        result /= 10;
        //printf("str[%d]=%c\n", i, str[i]);
    }
    return str;
}
#endif

int main() {
#if 0
    char *str = addStrings("19099", "222");
#elif 0
    char *str = addStrings("123456789", "987654321");
#elif 1
    char *str = addStrings("1", "9");
#endif
    printf("addStrings=%s\n", str);
    free(str);
    return 0;
}