#include <stdio.h>
#include <string.h>

void reverse(char str1[], int size) {
    for (int i = 0; i < size / 2; i++) {
        char temp = str1[i];
        str1[i] = str1[size - i - 1];
        str1[size - i - 1] = temp;
    }
}

int main() {
    char text[1000], reversed[1000];
    gets(text);

    strcpy(reversed, text);
    reverse(reversed, strlen(reversed));

    if (!strcmp(text, reversed)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}