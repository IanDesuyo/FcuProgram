#include <stdio.h>

int main() {
    int length;
    scanf("%d", &length);

    int nums[length];
    int n = 0;
    int val;

    for (int i = 0; i < length; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &val);

    for (int i = 0; i < length; i++) {
        if (nums[i] != val) {
            n++;
        }
    }
    printf("%d\n", n);

    return 0;
}