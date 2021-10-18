#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int n;
    char binary[8] = "00000000";

    scanf("%u", &n);

    for (int i = 7; i > 0; i--)
    {
        if (n >= pow(2, i))
        {
            binary[7 - i] = '1';
            n -= pow(2, i);
        }
    }
    if (n == 1)
    {
        binary[7] = '1';
    }

    printf("%s\n", binary);

    return 0;
}