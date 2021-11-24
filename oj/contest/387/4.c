#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int sum = 0;

        int m;
        scanf("%d", &m);

        int nums[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &nums[j]);
        }

        qsort(nums, m, sizeof(int), compare);

        for (int j = 0; j < m; j++) {
            sum += abs(nums[j] - nums[m / 2]);
        }

        printf("%d\n", sum);
    }

    return 0;
}