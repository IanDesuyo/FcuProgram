#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool canConstruct(char*, char*);

int main() {
    printf("%d\n", canConstruct("a", "b"));

    return 0;
}

// LeetCode

bool canConstruct(char* ransomNote, char* magazine) {
    int counter[26] = {0};
    for (int i = 0; i < strlen(magazine); i++) {
        counter[magazine[i] - 'a']++;
    }

    for (int i = 0; i < strlen(ransomNote); i++) {
        counter[ransomNote[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (counter[i] < 0) {
            return false;
        }
    }

    return true;
}