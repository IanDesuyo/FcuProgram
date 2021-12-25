#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[1002], b[1002];
    int lenA, lenB, maxLen, idx;
    int sum = 0;

    scanf("%s", a);
    scanf("%s", b);
    lenA = strlen(a);
    lenB = strlen(b);
    maxLen = idx = lenA > lenB ? lenA : lenB;

    char *ans = calloc(sizeof(char), maxLen + 1);

    while (lenA || lenB) {
        if (lenA) {
            sum += a[--lenA] - '0';
        }
        if (lenB) {
            sum += b[--lenB] - '0';
        }

        if (sum > 1) {
            ans[idx] = (sum - 2) + '0';
            sum = 1;
        } else {
            ans[idx] = sum + '0';
            sum = 0;
        }
        idx--;
    }
    if (sum) {
        ans[idx] = sum + '0';
        printf("%c", ans[idx]);
    }

    for (int i = 1; i < maxLen + 1; i++) {
        printf("%c", ans[i]);
    }
    printf("\n");

    free(ans);
    return 0;
}