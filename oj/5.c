#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

unsigned long lcm(unsigned long a, unsigned long b) {
    return a * b / gcd(a, b);
}

int main() {
    int x;
    unsigned long n, m, t;

    scanf("%d", x);
    for (int i = 0; i < x; i++) {
        scanf("%d %d", &n, &m);
        printf("%ld\n", lcm(n, m));
    }
}