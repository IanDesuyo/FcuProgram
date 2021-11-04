#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int longest = 0;
    char text[100];

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        gets(text);

        if (strlen(text) > longest) {
            longest = strlen(text);
        }
    }

    printf("%d", longest);

    return 0;
}