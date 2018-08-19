#include <stdio.h>

int state[] = {1,5,10,50,100,500,1000};

int romanToInt(char* s) {
    char *ptr = s;
    int cur_idx, last_idx = -1;
    int repeat = 0;
    int ret_sum = 0;
    while (*ptr != '\0')
    {
        switch (*ptr)
        {
            case 'I': cur_idx = 0; break;
            case 'V': cur_idx = 1; break;
            case 'X': cur_idx = 2; break;
            case 'L': cur_idx = 3; break;
            case 'C': cur_idx = 4; break;
            case 'D': cur_idx = 5; break;
            case 'M': cur_idx = 6; break;
        }
        //printf("*ptr=%c\tcur_idx=%d\tlast_idx=%d\trepeat=%d\tret_sum=%d\n", *ptr, cur_idx, last_idx, repeat, ret_sum);
        if (last_idx == -1) {
            repeat = 1;
        } else if (cur_idx == last_idx) {
            repeat++;
        } else if (cur_idx < last_idx) {
            ret_sum += repeat * state[last_idx];
            repeat = 1;
        } else if (cur_idx > last_idx) {
            ret_sum += state[cur_idx] - state[last_idx];
            repeat = 0;
        }
        last_idx = cur_idx;
        ptr++;
    }
    if (repeat != 0)
        ret_sum += repeat * state[last_idx];
    return ret_sum;
}

int main()
{
    char *input = "MCMXCIV";
    printf("Answer=%d\n", romanToInt(input));
    return 0;
}