#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getTarget(FILE* f) {
    char c;

    int target = 0;
    int isWithOther = 0;

    while ((c = fgetc(f)) != EOF) {
        // end
        if (c == ',') {
            break;
        }

        // with other
        if (c == '=') {
            isWithOther = 1;
            continue;
        }

        target = target * 10 + (c - '0');
    }

    if (isWithOther) {
        return -target;
    } else {
        return target;
    }
}

int findStore(int* targets, int index) {
    int target = targets[index];

    // < 0 means with other
    if (target < 0) {
        // so we find the store of the other
        target = findStore(targets, -target - 1);
    }

    // and update self for better performance
    targets[index] = target;

    return target;
}

int main() {
    int targets[100];

    FILE* f = fopen("input.txt", "r");

    int len = 0;
    // read data
    while (len < 100) {
        int target = getTarget(f);

        if (target == 0) {
            break;
        }

        targets[len++] = target;
    }

    // find store
    for (int i = 0; i < len; i++) {
        findStore(targets, i);
    }

    // save result
    FILE* out = fopen("output.txt", "w");

    for (int i = 0; i < len; i++) {
        fprintf(out, "%d", targets[i]);
        if (i != len - 1) {
            fprintf(out, ",");
        }
    }

    return 0;
}