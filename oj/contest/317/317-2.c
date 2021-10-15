#include <stdio.h>

int main()
{
    int year;
    int isLeap = 0;

    scanf("%d", &year);

    if (year % 4 == 0)
    {
        isLeap = 1;
    }
    if (year % 4 == 0 && year % 100 != 0)
    {
        isLeap = 1;
    }
    if (year % 100 == 0 && year % 400 != 0)
    {
        isLeap = 0;
    }
    if (year % 400 == 0)
    {
        isLeap = 1;
    }

    printf(isLeap == 1 ? "a leap year" : "a normal year");

    return 0;
}