#include <stdio.h>
#include <string.h>

char convert(char c) {
    char map[] = " `1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    if (c == ' ') {
        return c;
    }

    for (int i = 0; i < 48; i++) {
        if (map[i] == c) {
            return map[i - 2];
        }
    }

    return c;
}

int main() {
    char text;

    while ((text = getchar()) != EOF) {
        printf("%c", convert(text));
    }

    return 0;
}