#include <stdio.h>
int main()
{
    int a;
    char b;
    int c;

    scanf("%d %c %d", &a, &b, &c);

    switch (b)
    {
    // 加法
    case '+':
        printf("%d", a + c);
        break;
	// 測資的減號不是我想的減號 :(
    case '-':
        printf("%d", a - c);
        break;
	// 乘法
    case '*':
        printf("%d", a * c);
        break;
	// 除法
    case '/':
        if (c == 0)
        {
            printf("wrong input");
        }
        else
        {
            printf("%d", a / c);
        }
        break;
    }

    return 0;
}