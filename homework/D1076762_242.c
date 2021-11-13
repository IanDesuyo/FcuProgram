#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char*, char*);

int main() {
    printf("%d\n", isAnagram("anagram", "nagaram"));

    return 0;
}

// LeetCode

bool isAnagram(char* s, char* t) {
    int counter[26] = {0};
    if (strlen(s) != strlen(t)) {  // check string length
        return false;
    }

    for (int i = 0; i < strlen(s); i++) {
        counter[s[i] - 'a']++;
    }

    for (int i = 0; i < strlen(t); i++) {
        counter[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (counter[i] != 0) {
            return false;  // directly return false
        }
    }

    return true;
}