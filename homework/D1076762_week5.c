#include <stdio.h>

int main() {
    int cans, i;
    int drink;

    while (scanf("%d", &cans) != EOF) {
        drink = cans;  // you bought and drank n Cokes

        while (cans >= 3) {
            i = cans / 3;  // exchange 3 empty cans for a Coke
            drink += i;
            cans = i + cans % 3;
        }

        if (cans == 2) {  // borrow an empty can
            drink++;
        }

        printf("%d\n", drink);
    }

    return 0;
}