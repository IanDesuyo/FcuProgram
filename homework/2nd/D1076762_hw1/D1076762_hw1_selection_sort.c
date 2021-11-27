#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*, const void*);
int* selectionSort(int*, int);

int main() {
    int nums[5] = {3, 2, 5, 4, 1};
    int* sortedNums = selectionSort(nums, sizeof(nums) / sizeof(int));

    for (int i = 0; i < 5; i++) {  // print sorted nums
        printf("%d ", sortedNums[i]);
    }

    return 0;
}

int* selectionSort(int* nums, int numsSize) {
    int* newNums = malloc(numsSize * sizeof(int));  // dynamic memory allocation
    memcpy(newNums, nums, numsSize * sizeof(int));  // copy array

    for (int step = 0, min_num_index = 0; step < numsSize - 1; min_num_index = ++step) {
        for (int index = step + 1; index < numsSize; index++) {
            if (newNums[index] < newNums[min_num_index]) {  // find the index of minimal number
                min_num_index = index;
            }
        }

        if (min_num_index != step) {
            newNums[step] ^= newNums[min_num_index] ^= newNums[step] ^= newNums[min_num_index];  // Swap two numbers
        }
    }

    return newNums;
}