#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void*, const void*);
int* quickSort(int*, int);

int main() {
    int nums[5] = {3, 2, 5, 4, 1};
    int* sortedNums = quickSort(nums, sizeof(nums) / sizeof(int));

    for (int i = 0; i < 5; i++) {  // print sorted nums
        printf("%d ", sortedNums[i]);
    }

    return 0;
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* quickSort(int* nums, int numsSize) {
    int* newNums = malloc(numsSize * sizeof(int));  // dynamic memory allocation
    memcpy(newNums, nums, numsSize * sizeof(int));  // copy array

    qsort(newNums, numsSize, sizeof(int), compare);  // use qsort for sorting
    return newNums;
}