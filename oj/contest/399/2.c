#include <stdio.h>

long fibnonacci(int n) {
    if (n == 1) {
        return 1;
    } else if (n < 1) {
        return 0;
    }

    return fibnonacci(n - 1) + fibnonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%ld\n", fibnonacci(n));

    return 0;
}