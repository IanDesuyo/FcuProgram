#include <stdio.h>

int main()
{
    char temp = 0;
    char STRINGS[][11] = {
        "hello,world",
        "hello      ",
        "      world",
        "he         ",
        "he      r d",
        "   lo w    ",
        "    o    ld",
        "hello,world"};

    printf("press enter to continute\n");

    for (int i = 0; i < 8; i++)
    {
        scanf("%c", &temp);
        printf("%s", STRINGS[i]);
    }
}