#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;
        int flag = 0;
        while (j >= 0 & nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
            flag = 1;
        }
        nums[j + 1] = key;

        if (flag) {
            for (int k = 0; k < n; k++) {
                printf("%d", nums[k]);
                if (k < n - 1) {
                    printf(" ");
                } else {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}