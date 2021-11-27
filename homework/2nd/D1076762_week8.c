#include <stdio.h>

int upper(int character) {
    return character >= 'a' && character <= 'z' ? character - 32 : character;  // return (character - 32) if the character is lowercase, otherwise return itself
}

int lower(int character) {
    return character >= 'A' && character <= 'Z' ? character + 32 : character;  // return (character + 32) if the character is uppercase, otherwise return itself
}

int string_length(char string[]) {
    int length = 0;
    while (1) {
        if (string[length] == '\0') {  // loop until read \0
            return length;
        }
        length++;
    }
}

int main() {
    char string[] = "HellO? World!!!/^^";

    printf("%s\n", string);

    printf("string length: %d\n", string_length(string));

    for (int i = 0; i < string_length(string); i++)

    {
        printf("%c", lower(string[i]));
    }

    printf("\n");

    for (int i = 0; i < string_length(string); i++) {
        printf("%c", upper(string[i]));
    }

    printf("\n");
}
