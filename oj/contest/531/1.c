#include <stdio.h>

void printLine(char C, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", C);
    }
    printf("\n");
}

int main() {
    char C;
    int L, N;

    scanf("%c %d %d", &C, &L, &N);

    // run N times

    for (int i = 0; i < N; i++) {
        // up
        for (int i = 1; i <= L; i++) {
            printLine(C, i);
        }
        // down
        for (int i = L - 1; i > 1; i--) {
            printLine(C, i);
        }
    }

    if (L > 1) {
        printLine(C, 1);
    }

    return 0;
}
