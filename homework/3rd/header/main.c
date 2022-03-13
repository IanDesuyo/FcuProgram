#include "lib/bubblesort.h"
#include <stdio.h>

int main() {
    int nums[5] = {10, 87, 12, 24, 4};
    bubbleSort(nums, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}