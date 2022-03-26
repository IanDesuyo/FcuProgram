// Fig. 7.15: fig07_15.c
// Putting values into an array, sorting the values into
// ascending order, and printing the resulting array.
#include "q2.h"

int q2(void) {
    // initialize array a
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    puts("Data items in original order");

    // loop through array a
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    bubbleSort(a, SIZE);  // sort the array

    puts("\nData items in ascending order");

    // loop through array a
    for (size_t i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }

    puts("\nData items in descending order");

    // loop through array a
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%4d", a[i]);
    }

    puts("");
}

// sort an array of integers using bubble sort algorithm
void bubbleSort(int *array, size_t size) {
    // loop to control passes
    for (unsigned int pass = 0; pass < size - 1; ++pass) {
        // loop to control comparisons during each pass
        for (size_t j = 0; j < size - 1; ++j) {
            // swap adjacent elements if theye out of order
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

// swap values at memory locations to which element1Ptr and
// element2Ptr point
void swap(int *element1Ptr, int *element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}