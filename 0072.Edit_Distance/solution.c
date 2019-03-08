#include <stdio.h>
#include <string.h>

#define min(x,y) (((x)<(y))?(x):(y))
int minDistance(char* word1, char* word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);
    int dp_map[word1_len+1][word2_len+1];
    for (int i = 0; i <= word1_len; i++) {
        dp_map[i][0] = i;
    }
    for (int j = 0; j <= word2_len; j++) {
        dp_map[0][j] = j;
    }
    for (int i = 1; i <= word1_len; i++) {
        for (int j = 1; j <= word2_len; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp_map[i][j] = dp_map[i-1][j-1];
            } else {
                dp_map[i][j] = min(dp_map[i-1][j-1], min(dp_map[i-1][j], dp_map[i][j-1])) + 1;
            }
        }
    }
#if 0    
    for (int i = 0; i <= word1_len; i++) {
        for (int j = 0; j <= word2_len; j++) {
            printf("%d ", dp_map[i][j]);
        }
        printf("\n");
    }
#endif
    return dp_map[word1_len][word2_len];
}

int main() {
    char *word1 = "horse";
    char *word2 = "ros";
    printf("min distance=%d\n", minDistance(word1, word2));
    return 0;
}