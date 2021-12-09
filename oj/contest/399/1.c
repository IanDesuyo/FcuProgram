#include <stdio.h>

long power(int n) {
    if (n == 1) {
        return 1;
    }

    return n * power(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%ld\n", power(n));

    return 0;
}