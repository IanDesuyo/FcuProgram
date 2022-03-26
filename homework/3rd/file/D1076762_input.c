#include <stdio.h>

int main() {
    FILE *fPtr;
    int num;

    if ((fPtr = fopen("./D1076762.dat", "wb")) == NULL) {
        printf("ERROR\n");
    }

    fwrite("D1076762", sizeof(char), 8, fPtr);
    scanf("%d", &num);

    fwrite(&num, sizeof(int), 1, fPtr);

    return 0;
}