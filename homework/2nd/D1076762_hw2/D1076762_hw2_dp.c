#include <stdio.h>

int climbStairs(int);

int main() {
    printf("%d\n", climbStairs(3));
    return 0;
}

// LeetCode

int climbStairs(int n) {
    int stairs[45] = {1, 2};  // 1 <= n <= 45
    for (int i = 2; i < n; i++) {
        stairs[i] = stairs[i - 1] + stairs[i - 2];
    }

    return stairs[n - 1];
}