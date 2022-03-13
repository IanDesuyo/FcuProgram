#include <stdio.h>

enum Color {
    RED = 10,
    BLUE = 2,
    GREEN = 3,
};

int main() {
    int n;
    scanf("%d", &n);

    switch (n) {
        case RED:
            printf("I like red.\n");
            break;
        case BLUE:
            printf("I like blue.\n");
            break;
        case GREEN:
            printf("I like green.\n");
            break;
        default:
            printf("Nope.\n");
            break;
    }

    return 0;
}