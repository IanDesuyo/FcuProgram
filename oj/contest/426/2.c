#include <stdio.h>

int main() {
    char text;
    int flag = 0;

    while ((text = getchar()) != EOF) {
        if (text == '\r' || text == '\n') {
            printf("%c", text);
            continue;
        }

        if (text == '"') {
            if (flag) {
                printf("''");
            } else {
                printf("``");
            }
            flag = !flag;
        } else {
            printf("%c", text);
        }
    }

    return 0;
}