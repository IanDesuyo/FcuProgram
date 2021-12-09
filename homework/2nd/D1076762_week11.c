#include <stdio.h>
#include <stdlib.h>

// define the structure of coordinate
typedef struct coordinate {
    int x;
    int y;
    int z;
} Coordinate;

int compare(const void* a, const void* b) {
    Coordinate ca = *(Coordinate*)a;
    Coordinate cb = *(Coordinate*)b;

    if (ca.x != cb.x) {  // compare x
        return ca.x - cb.x;
    } else if (ca.y != cb.y) {  // compare y
        return ca.y - cb.y;
    } else {  // compare z
        return ca.z - cb.z;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // load the coordinates
    Coordinate coordinates[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &coordinates[i].x, &coordinates[i].y, &coordinates[i].z);
    }

    // sort the coordinates
    qsort(coordinates, n, sizeof(Coordinate), compare);

    // print the coordinates
    for (int i = 0; i < n; i++) {
        printf("%p %p %p\n", &coordinates[i].x, &coordinates[i].y, &coordinates[i].z);
        printf("%d %d %d\n", *&coordinates[i].x, *(&coordinates[i].x + 1), *(&coordinates[i].x + 2));
        if (i != n - 1) {
            printf("----------\n");
        }
    }

    return 0;
}