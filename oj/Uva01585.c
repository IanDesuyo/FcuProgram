#include <stdio.h>
#include <string.h>

int main() {
    int t;
    int temp;
    int score, combo;
    char text[80];
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        score = 0;
        combo = 0;
        scanf("%s", text);

        for (int j = 0; j < strlen(text); j++) {
            if (text[j] == 'O') {
                combo++;
            } else {
                combo = 0;
            }

            score += combo;
        }
        printf("%d\n", score);
    }

    return 0;
}