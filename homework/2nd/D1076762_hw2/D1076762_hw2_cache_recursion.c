#include <stdio.h>

int climbStairs(int);

int main() {
    printf("%d\n", climbStairs(3));
    return 0;
}

// LeetCode

int cache[45] = {0};  // 1 <= n <= 45

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    if (cache[n - 1]) {
        return cache[n - 1];
    }
    cache[n - 1] = climbStairs(n - 1) + climbStairs(n - 2);
    return cache[n - 1];
}