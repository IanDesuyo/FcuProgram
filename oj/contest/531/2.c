#include <stdio.h>

int main() {
    int N;

    scanf("%d", &N);

    int array[N][N];
    int x, y;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // row
    for (int i = 0; i < N; i++) {
        x = i;
        y = 0;

        while (x >= 0) {
            printf("%d%c", array[x--][y++], "\n "[x > 0]);
        }
    }

    // col
    for (int i = 1; i < N; i++) {
        x = N - 1;
        y = i;

        while (y < N) {
            printf("%d%c", array[x--][y++], "\n "[y < N - 1]);
        }
    }

    return 0;
}