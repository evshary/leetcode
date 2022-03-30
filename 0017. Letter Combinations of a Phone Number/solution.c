#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_map[] = {NULL,
                   NULL,   //1
                   "abc",  //2
                   "def",  //3
                   "ghi",  //4
                   "jkl",  //5
                   "mno",  //6
                   "pqrs", //7
                   "tuv",  //8
                   "wxyz"  //9
                  };

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
    char **answer;
    int digit_len = strlen(digits);
    int *numbers;

    if(digit_len == 0)
        return NULL;
    numbers = malloc(sizeof(int) * digit_len);

    /* Transform number to integer */
    *returnSize = 1;
    for (int i = 0; i < digit_len; i++) {
        numbers[i] = digits[i] - 0x30;
        /* Calculate the returnSize */
        *returnSize *= strlen(str_map[numbers[i]]);
    }

    /* Malloc answer */
    answer = (char **)malloc(sizeof(char *) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        int tmp_returnSize = i;
        answer[i] = malloc(sizeof(char) * digit_len + 1);
        /* Get the answer string */
        answer[i][digit_len] = 0;
        for (int j = digit_len-1; j >= 0; j--) {
            int cur_num = numbers[j];
            answer[i][j] = str_map[cur_num][tmp_returnSize % strlen(str_map[cur_num])];
            tmp_returnSize /= strlen(str_map[cur_num]);
        }
    }

    free(numbers);
    return answer;
}

int main()
{
    char *input = "23";
    int returnSize;
    char **answer;

    answer = letterCombinations(input, &returnSize);
    printf("returnSize: %d\n", returnSize);
    printf("Answer: ");
    for (int i = 0; i < returnSize; i++)
        printf("%s ", answer[i]);
    printf("\n");

    // Free resource
    for (int i = 0; i < returnSize; i++)
        free(answer[i]);
    free(answer);

    return 0;
}