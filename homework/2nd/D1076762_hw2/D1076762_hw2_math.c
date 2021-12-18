#include <math.h>
#include <stdio.h>

int climbStairs(int);

int main() {
    printf("%d\n", climbStairs(3));
    return 0;
}

// LeetCode

int climbStairs(int n) {
    double rootOf5 = pow(5, 0.5);
    double phi = (1 + rootOf5) / 2;
    return round(pow(phi, n + 1) / rootOf5);
}