#include <math.h>
#include <stdio.h>

int main() {
    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        printf("%d\n", abs(i - j));
    }

    return 0;
}