#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    scanf("%d", &n);

    int scores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    qsort(scores, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%d", scores[i]);
        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    printf("%d\n%d\n%d\n", scores[0], scores[n % 2 ? n / 2 : n / 2 - 1], scores[n - 1]);
}