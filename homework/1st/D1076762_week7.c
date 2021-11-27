#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int alphabet[26] = {0};
    char text[1000];

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(text);

        for (int j = 0; j < strlen(text); j++) {
            if (text[j] >= 'a' && text[j] <= 'z') {
                alphabet[text[j] - 'a']++;
            } else if (text[j] >= 'A' && text[j] <= 'Z') {
                alphabet[text[j] - 'A']++;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] > 0) {
            printf("%c %d\n", i + 'A', alphabet[i]);
        }
    }

    return 0;
}