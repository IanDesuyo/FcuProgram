#include <stdio.h>

int main() {
    int cans, i;
    int drink;

    while (scanf("%d", &cans) != EOF) {
        drink = cans;

        while (cans >= 3) {
            i = cans / 3;
            drink += i;
            cans = i + cans % 3;
        }

        if (cans == 2) {
            drink++;
        }

        printf("%d\n", drink);
    }

    return 0;
}