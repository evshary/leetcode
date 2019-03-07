#include <stdio.h>
#include <string.h>

#define max(x,y) ((x)>(y))?(x):(y)
int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    int stack_array[len];
    int stack_empty_ptr = 0;
    int tmp_max_len;
    int max_len = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') { // push 0 into stack while '('
            stack_array[stack_empty_ptr] = 0;
            stack_empty_ptr++;
        } else { // s[i] == ')'
            tmp_max_len = 0;
            // find the 0, which stands for unmatching '('
            while(stack_empty_ptr != 0 && stack_array[stack_empty_ptr-1] != 0) {
                tmp_max_len += stack_array[stack_empty_ptr-1];
                stack_empty_ptr--;
            }
            if (stack_empty_ptr == 0) { // while 0 is not found
                max_len = max(max_len, tmp_max_len);
            } else { // while 0 is found
                stack_array[stack_empty_ptr-1] += 2 + tmp_max_len;
            }
        }
    }
    // After going through array, check the max sum of the continuous non-zero numbers remaining in the stack
    tmp_max_len = 0;
    while(stack_empty_ptr != 0) {
        if (stack_array[stack_empty_ptr-1] != 0) {
            tmp_max_len += stack_array[stack_empty_ptr-1];
            max_len = max(max_len, tmp_max_len);
        } else {
            tmp_max_len = 0;
        }
        stack_empty_ptr--;
    }
    return max_len;  
}

int main() {
    char *case1 = ")()())";
    char *case2 = "()(()";
    char *case3 = "((())";
    char *case4 = "(()()(()";
    printf("%s: longest valid parentheses=%d\n", case1, longestValidParentheses(case1));
    printf("%s: longest valid parentheses=%d\n", case2, longestValidParentheses(case2));
    printf("%s: longest valid parentheses=%d\n", case3, longestValidParentheses(case3));
    printf("%s: longest valid parentheses=%d\n", case4, longestValidParentheses(case4));
    return 0;
}