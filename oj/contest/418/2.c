#include <stdio.h>
#include <string.h>

int main() {
    char n[1001];
    int odd, even;

    while (scanf("%s", n) != EOF && strcmp(n, "0")) {
        odd = 0;
        even = 0;
        for (int i = 0; i < strlen(n); i++) {
            if (i % 2) {
                even += n[i] - 48;
            } else {
                odd += n[i] - 48;
            }
        }

        printf("%s is%s a multiple of 11.\n", n, (even - odd) % 11 ? " not" : "");
    }

    return 0;
}