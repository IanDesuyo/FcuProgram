#include <stdio.h>
#include <string.h>

void calc(long long x) {
    if (x / 10000000) {
        calc(x / 10000000);
        printf(" kuti");
        x %= 10000000;
    }
    if (x / 100000) {
        calc(x / 100000);
        printf(" lakh");
        x %= 100000;
    }
    if (x / 1000) {
        calc(x / 1000);
        printf(" hajar");
        x %= 1000;
    }
    if (x / 100) {
        calc(x / 100);
        printf(" shata");
        x %= 100;
    }
    if (x) {
        printf(" %lld", x);
    }
}

int main() {
    long long num;
    int count = 1;

    while (scanf("%lld", &num) != EOF) {
        printf("%4d.", count++);
        if (num) {
            calc(num);
        } else {
            printf(" 0");
        }
        printf("\n");
    }

    return 0;
}