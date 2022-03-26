#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fPtr;
    char studentId[9];
    int num;
    char temp[21];

    if ((fPtr = fopen("./D1076762.dat", "rb+")) == NULL) {
        printf("ERROR\n");
    }

    fread(studentId, sizeof(char), 8, fPtr);
    fread(&num, sizeof(int), 1, fPtr);

    printf("%s\n", studentId);
    printf("%-6s: %20d\n", "input", num);
    itoa(num, temp, 2);
    printf("%-6s: %20s\n", "BIN", temp);
    itoa(num, temp, 3);
    printf("%-6s: %20s\n", "3", temp);
    printf("%-6s: %20o\n", "OCT", num);
    printf("%-6s: %20d\n", "DEC", num);
    printf("%-6s: %20x\n", "HEX", num);

    return 0;
}