#include <stdio.h>

int main() {
    unsigned int a, b;
    unsigned int carry, n;
    while (scanf("%d %d", &a, &b) != EOF && !(a == 0 && b == 0)) {
        carry = 0;
        while (!(a == 0 && b == 0)) {
            n = a % 10 + b % 10 + n / 10;
            a /= 10;
            b /= 10;

            if (n / 10 > 0) {
                carry++;
            }
        }

        if (carry == 0) {
            printf("No carry operation.\n");
        } else if (carry == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", carry);
        }
    }

    return 0;
}