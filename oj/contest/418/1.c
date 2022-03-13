#include <stdio.h>

int loop(int n, int depth) {
    if (n == 1) {
        return depth;
    }
    return loop(n % 2 ? 3 * n + 1 : n / 2, depth + 1);
}

int main() {
    int i, j;
    int longest;
    int t;
    int swaped;
    while (scanf("%d %d", &i, &j) != EOF) {
        swaped = 0;
        longest = 0;
        if (i > j) {
            i ^= j ^= i ^= j;
            swaped = 1;
        }
        for (int x = i; x <= j; x++) {
            t = loop(x, 1);
            if (t > longest) {
                longest = t;
            }
        }

        if (swaped) {
            printf("%d %d %d\n", j, i, longest);
        } else {
            printf("%d %d %d\n", i, j, longest);
        }
    }

    return 0;
}