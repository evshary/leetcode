#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 15
char state[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void add_repeat_num(char *num_str, char add_num, int repeat)
{
    while (repeat) {
        num_str[strlen(num_str)] = add_num;
        repeat--;
    }
}

char* intToRoman(int num) {
    int i, cur_base = 1000;
    char *ret_num = malloc(MAX_SIZE);
    memset(ret_num, 0, MAX_SIZE);
    for (i = 6; i >= 0; i = i-2) {
        switch (num / cur_base) {
            case 1:
                add_repeat_num(ret_num, state[i], 1);
                break;
            case 2:
                add_repeat_num(ret_num, state[i], 2);
                break;
            case 3:
                add_repeat_num(ret_num, state[i], 3);
                break;
            case 4:
                add_repeat_num(ret_num, state[i], 1);
                add_repeat_num(ret_num, state[i+1], 1);
                break;
            case 5:
                add_repeat_num(ret_num, state[i+1], 1);
                break;
            case 6:
                add_repeat_num(ret_num, state[i+1], 1);
                add_repeat_num(ret_num, state[i], 1);
                break;
            case 7:
                add_repeat_num(ret_num, state[i+1], 1);
                add_repeat_num(ret_num, state[i], 2);
                break;
            case 8:
                add_repeat_num(ret_num, state[i+1], 1);
                add_repeat_num(ret_num, state[i], 3);
                break;
            case 9:
                add_repeat_num(ret_num, state[i], 1);
                add_repeat_num(ret_num, state[i+2], 1);
                break;
        }
        //printf("i=%d\tnum=%d\tcur_base=%d\tret_num=%s\n", i, num, cur_base, ret_num);
        num = num % cur_base;
        cur_base /= 10;
    }
    return ret_num;
}

int main()
{
    printf("Answer=%s\n", intToRoman(58));
    return 0;
}