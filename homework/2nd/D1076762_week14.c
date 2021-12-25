#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  (╯°□°）╯︵ 口口口
// flip array　口口口
void flip(int row, int col, int data[row][col], int ans[col][row]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            ans[j][i] = data[i][j];
        }
    }
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    // create array
    int data[row][col];
    int ans[col][row];

    // input
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    flip(row, col, data, ans);

    // output
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}