#include <stdbool.h>
#include <stdio.h>

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int min = __INT_MAX__;
    int max = 0;
    for (int i = 0; i < tripsSize; i++) {
        if (trips[i][1] < min) {
            min = trips[i][1];
        }
        if (trips[i][2] > max) {
            max = trips[i][2];
        }
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < tripsSize; j++) {
            if (trips[j][1] == i) {
                capacity -= trips[j][0];
            }
            if (trips[j][2] == i) {
                capacity += trips[j][0];
            }
        }

        if (capacity < 0) {
            return false;
        }
    }
    return true;
}