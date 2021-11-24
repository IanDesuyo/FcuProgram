#include <stdio.h>

int main() {
    int n;
    int temp;
    scanf("%d", &n);

    int sum = (n + 1) * (n + 2) / 2;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        sum -= temp;
    }

    printf("%d\n", sum);
    return 0;
}