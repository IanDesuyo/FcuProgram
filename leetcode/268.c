#include <stdio.h>

int missingNumber(int*, int);

int main() {
    int nums[] = {3, 0, 1};
    printf("%d\n", missingNumber(nums, 3));
}

// LeetCode

int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 1; i <= numsSize; i++) {
        sum += i - nums[i - 1];
    }

    return sum;
}