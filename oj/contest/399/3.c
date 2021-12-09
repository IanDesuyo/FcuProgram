#include <stdio.h>

int binraySearch(int* nums, int start, int end, int target) {
    int middle = (end - start) / 2 + start;
    if (nums[middle] == target) {
        return middle;
    }

    if (nums[middle] < target) {
        return binraySearch(nums, middle + 1, end, target);
    } else if (nums[middle] > target) {
        return binraySearch(nums, start, middle - 1, target);
    }
}

int main() {
    int n, target;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);
    printf("%d\n", binraySearch(nums, 0, n - 1, target));

    return 0;
}