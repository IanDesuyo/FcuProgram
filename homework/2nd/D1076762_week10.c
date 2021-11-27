#include <stdio.h>

int F[32] = {0, 1};

void initF() {
    for (int i = 2; i < 32; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

int main() {
    initF();  // create a array of Fibonacci numbers

    int t;
    int a, b;
    int count;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);

        if (a > b) {
            a ^= b ^= a ^= b;  // swap a and b
        }

        count = 0;
        for (int i = 0; i < 32; i++) {
            if (F[i] > b) {
                break;  // break when F[i] > b
            } else if (F[i] >= a) {
                printf("%d\n", F[i]);
                count++;
            }
        }

        printf("%d\n", count);  // print the number of Fibonacci numbers in [a, b]
        if (i < t - 1) {
            printf("------\n");  // print a line between two test cases
        }
    }

    return 0;
}
