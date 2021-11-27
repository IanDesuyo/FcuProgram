#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* sortArray(int*, int, int*);

int main() {
    int nums[] = {5, 2, 3, 1};
    int returnSize;
    int* sorted = sortArray(nums, 4, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", sorted[i]);
    }
}

// LeetCode

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int* newNums = malloc(numsSize * sizeof(int));
    memcpy(newNums, nums, numsSize * sizeof(int));

    qsort(newNums, numsSize, sizeof(int), compare);

    *returnSize = numsSize;
    return newNums;
}