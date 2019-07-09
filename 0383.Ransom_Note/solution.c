#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int dict[26] = {0};
    int length = strlen(magazine);
    for (int i = 0; i < length; i++) {
        dict[magazine[i] - 'a']++;
    }
    length = strlen(ransomNote);
    for (int i = 0; i < length; i++) {
        if (--dict[ransomNote[i]-'a'] < 0)
            return false;
    }
    return true;
}

int main() {
    char *ransomNote = "aa";
    char *magazine = "baac";
    if (canConstruct(ransomNote, magazine))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}