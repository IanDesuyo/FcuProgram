#include <stdio.h>

int climbStairs(int);

int main() {
    printf("%d\n", climbStairs(3));
    return 0;
}

// LeetCode

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}