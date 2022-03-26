// Fig. 6.7 Analyzing a student poll.
#include "q1.h"

// function main begins program execution
int q1(void) {
    // initialize frequency counters to 0
    int frequency[FREQUENCY_SIZE] = {0};

    // place the survey responses in the responses array
    int responses[RESPONSES_SIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10,
                                     1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6,
                                     5, 6, 7, 5, 6, 4, 8, 6, 8, 10};

    bubbleSort(responses);
    mean(responses);

    printf("\nThe sorted array is\n");
    printArray(responses);

    printf("\n\nThe median is %d\n\n", responses[RESPONSES_SIZE / 2]);

    // for each answer, select value of an element of array responses
    // and use that value as an index in array frequency to
    // determine element to increment
    for (size_t answer = 0; answer < RESPONSES_SIZE; ++answer) {
        ++frequency[responses[answer]];
    }

    // display results
    printf("%s%17s\n", "Rating", "Frequency");

    // output the frequencies in a tabular format
    for (size_t rating = 1; rating < FREQUENCY_SIZE; ++rating) {
        printf("%6d%17d\n", rating, frequency[rating]);
    }
}

void mean(const unsigned int answer[]) {
    unsigned int total = 0;  // variable to hold sum of array elements

    // total response values
    for (size_t j = 0; j < RESPONSES_SIZE; ++j) {
        total += answer[j];
    }

    printf("The total is %d\n", total);
    printf("The mean is %.4f\n", (float)total / RESPONSES_SIZE);
}

void bubbleSort(unsigned int a[]) {
    // loop to control number of passes
    for (unsigned int pass = 1; pass < RESPONSES_SIZE; ++pass) {
        // loop to control number of comparisons per pass
        for (size_t j = 0; j < RESPONSES_SIZE - 1; ++j) {
            // swap elements if out of order
            if (a[j] > a[j + 1]) {
                unsigned int hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

void printArray(const unsigned int a[]) {
    // output array contents
    for (size_t j = 0; j < RESPONSES_SIZE; ++j) {
        if (j && j % 20 == 0) {  // begin new line every 20 values
            printf("\n");
        }

        printf("%3u", a[j]);
    }
}