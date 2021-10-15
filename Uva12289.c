#include <stdio.h>

int main()
{
    char a[][5] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        int count[10] = {0};
        char text[5];
        scanf("%s", text);

        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (text[j] == a[k][j])
                {
                    count[k]++;
                }
            }
        }
        
        for (int i = 0; i < 10; i++)
        {
            printf("%d: %d", i+1, count[i]);
        }
        
    }
}