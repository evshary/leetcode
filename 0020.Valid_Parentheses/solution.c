#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum {
    BRACKET1 = 0,  //'()'
    BRACKET2 = 1,  //'{}'
    BRACKET3 = 2,  //'[]'
    BRACKET_KIND
};

#define PUSH_BRACKET(kind) \
    do { \
        stack_array[next_empty_ptr] = kind; \
        next_empty_ptr++; \
    } while(0);
#define TRY_POP_BRACKET(kind) \
    do { \
        if (next_empty_ptr <= 0) \
            return false; \
        next_empty_ptr--; \
        if (stack_array[next_empty_ptr] != kind) \
            return false; \
    } while(0);

bool isValid(char* s) {
    int len = strlen(s);
    if (len == 0) return true;
    int stack_array[len];
    int next_empty_ptr = 0;
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '(':
                PUSH_BRACKET(BRACKET1);
                break;
            case '{':
                PUSH_BRACKET(BRACKET2);
                break;
            case '[':
                PUSH_BRACKET(BRACKET3);
                break;
            case ')':
                TRY_POP_BRACKET(BRACKET1);
                break;
            case '}':
                TRY_POP_BRACKET(BRACKET2);
                break;
            case ']':
                TRY_POP_BRACKET(BRACKET3);
                break;
        }
    }
    if (next_empty_ptr != 0)
        return false;
    else
        return true;
}

int main() {
    //char *input = "()[]{}";
    //char *input = "([)]";
    //char *input = "]";
    char *input = "(";
    if (isValid(input))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}