#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int* _deck;  // the array won't be shuffled
    int* deck;   // the array would be shuffled
    int size;    // array size
} Solution;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));  // malloc solution
    obj->size = numsSize;
    obj->_deck = (int*)malloc(sizeof(int) * obj->size);  // malloc _deck array
    obj->deck = (int*)malloc(sizeof(int) * obj->size);   // malloc deck array
    memcpy(obj->_deck, nums, sizeof(int) * obj->size);   // memcpy nums to _deck array
    memcpy(obj->deck, nums, sizeof(int) * obj->size);    // memcpy nums to deck array

    return obj;
}

int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->size;

    return obj->_deck;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->size;

    // random swap deck
    for (int i = 0; i < *retSize; i++) {
        swap(&obj->deck[i], &obj->deck[rand() % *retSize]);
    }

    return obj->deck;
}

void solutionFree(Solution* obj) {
    free(obj);
}

int main() {
    srand(time(NULL));
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution* obj = solutionCreate(nums, 10);
    int retSize = 0;
    int* ret = solutionShuffle(obj, &retSize);
    printf("Shuffled deck: ");
    for (int i = 0; i < retSize; i++) {
        printf("%2d ", ret[i]);
    }
    printf("\n");
    ret = solutionReset(obj, &retSize);
    printf("Reset deck:    ");
    for (int i = 0; i < retSize; i++) {
        printf("%2d ", ret[i]);
    }
    printf("\n");
    solutionFree(obj);

    return 0;
}