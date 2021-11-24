#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*, const void*);
int* insertionSort(int*, int);

int main() {
    int nums[5] = {3, 2, 5, 4, 1};
    int* sortedNums = insertionSort(nums, sizeof(nums) / sizeof(int));

    for (int i = 0; i < 5; i++) {  // print sorted nums
        printf("%d ", sortedNums[i]);
    }

    return 0;
}

int* insertionSort(int* nums, int numsSize) {
    int* newNums = malloc(numsSize * sizeof(int));  // dynamic memory allocation
    memcpy(newNums, nums, numsSize * sizeof(int));  // copy array

    int hold, index;
    for (int step = 1; step < numsSize; step++) {  // start from 1 because the first number is already sorted
        hold = newNums[step];                      // hold numsSize[step]
        index = step - 1;                          // The index from 0 to step - 1 is already sorted

        while (index >= 0 && newNums[index] > hold) {  // find the correct index for hold
            newNums[index + 1] = newNums[index];
            index -= 1;
        }

        newNums[index + 1] = hold;  // put the hold number in the correct index
    }

    return newNums;
}