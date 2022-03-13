#include <stdio.h>

int chalkReplacer(int* chalk, int chalkSize, int k) {
    unsigned long total = 0;
    for (int i = 0; i < chalkSize; i++) {
        total += chalk[i];
    }
    k %= total;

    int current = 0;
    while (k >= chalk[current]) {
        k -= chalk[current];
        current++;
        if (current == chalkSize) {
            current = 0;
        };
    };

    return current;
}

int main() {
    int chalk[] = {3, 4, 1, 2};
    int k = 25;

    printf("%d\n", chalkReplacer(chalk, 4, k));

    return 0;
}