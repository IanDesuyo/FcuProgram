#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char num1[1002], num2[1002];
    int len1, len2, maxLen, idx;
    int sum = 0;

    scanf("%s", num1);
    scanf("%s", num2);

    len1 = strlen(num1);
    len2 = strlen(num2);
    maxLen = idx = (len1 > len2 ? len1 : len2);
    char *res = calloc(sizeof(char), maxLen + 1);

    while (len1 || len2) {
        if (len1) {
            sum += num1[--len1] - '0';
        }
        if (len2) {
            sum += num2[--len2] - '0';
        }

        res[idx--] = (sum % 10) + '0';
        sum /= 10;
    }
    if (sum) {
        res[idx] = sum + '0';
        printf("%c", res[idx]);
    }

    for (int i = 1; i <= maxLen; i++) {
        printf("%c", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}