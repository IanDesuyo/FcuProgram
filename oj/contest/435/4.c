#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *data, int start, int end) {
    for (int i = 0; i < (end - start + 1) / 2; i++) {
        if (data[start + i] == data[end - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char data[1002];
    int len;
    int count = 0;

    scanf("%s", data);
    len = strlen(data);

    for (int i = 0, j = i + 1; i < len; i = j + 1, j = i + 1) {
        while (!check(data, i, j)) {
            j += 2;
        }
        count++;
    }

    printf("%d\n", count);

    return 0;
}