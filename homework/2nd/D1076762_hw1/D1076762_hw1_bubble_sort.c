#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*, const void*);
int* bubbleSort(int*, int);

int main() {
    int nums[5] = {3, 2, 5, 4, 1};
    int* sortedNums = bubbleSort(nums, sizeof(nums) / sizeof(int));

    for (int i = 0; i < 5; i++) {  // print sorted nums
        printf("%d ", sortedNums[i]);
    }

    return 0;
}

int* bubbleSort(int* nums, int numsSize) {
    int* newNums = malloc(numsSize * sizeof(int));  // dynamic memory allocation
    memcpy(newNums, nums, numsSize * sizeof(int));  // copy array

    int modified = 0;
    for (int size = 0; size < numsSize; size++) {
        for (int loop = 0; loop < numsSize - 1 - size; loop++) {
            if (newNums[loop] > newNums[loop + 1]) {                                       // if left is greater than right
                newNums[loop] ^= newNums[loop + 1] ^= newNums[loop] ^= newNums[loop + 1];  // Swap two numbers
                modified = 1;
            }
        }
        if (!modified) {  // not modified means sorting is complete
            break;
        }
    }

    return newNums;
}