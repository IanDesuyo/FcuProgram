#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {  // qsort compare function
    return *(int*)a - *(int*)b;
}

int main() {
    // score in range[0, 100], so -1 and 101 should not exist.
    int highestWorst = -1;
    int lowestBest = 101;

    int n;
    scanf("%d", &n);

    int studentScores[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &studentScores[i]);  // read scores
    }

    qsort(studentScores, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%d", studentScores[i]);

        if (i < n - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    for (int i = 0; i < n; i++) {
        if (studentScores[i] < 60 && studentScores[i] > highestWorst) {  // check the highest score that less than 60
            highestWorst = studentScores[i];
        } else if (studentScores[i] >= 60 && studentScores[i] < lowestBest) {  // check the lowest score that more or equal to 60
            lowestBest = studentScores[i];
        }
    }

    // print result
    if (highestWorst == -1) {
        printf("best case\n");
    } else {
        printf("%d\n", highestWorst);
    }

    if (lowestBest == 101) {
        printf("worst case\n");
    } else {
        printf("%d\n", lowestBest);
    }

    return 0;
}