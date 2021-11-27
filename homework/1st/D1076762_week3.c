#include <stdio.h>
#include <math.h>

int planA(int tickets, int drinks)
{
    // 凡購買電影票及飲料者，可折抵 10 元。
    int coupon = 0;
    if (tickets >= 1 && drinks >= 1)
    {
        coupon = 10;
    }
    return tickets * 300 + drinks * 40 - coupon;
}

int planB(int tickets, int drinks)
{
    // 購買兩張以上電影票，結帳金額打 9 折。

    float discount = 1.0;
    if (tickets >= 2)
    {
        discount = 0.9;
    }

    return round((tickets * 300 + drinks * 40) * discount);
}

int planC(int tickets, int drinks)
{   
    // 購買兩張以上電影票，且有購買飲料，結帳金額打 85 折後再減 30 元。
    float discount = 1.0;
    int coupon = 0;
    if (tickets >= 2 && drinks >= 1)
    {
        discount = 0.85;
        coupon = 30;
    }

    return round((tickets * 300 + drinks * 40) * discount - coupon);
}

int main()
{
    // Declare variables
    int tickets;
    int drinks;
    int prices[3];

    scanf("%d %d", &tickets, &drinks);

    // Calculate plan's prices
    prices[0] = planA(tickets, drinks);
    prices[1] = planB(tickets, drinks);
    prices[2] = planC(tickets, drinks);

    if (prices[2] < prices[1])
    {
        printf("%d", prices[2]);
    }
    else if (prices[1] < prices[0])
    {
        printf("%d", prices[1]);
    }
    else
    {
        printf("%d", prices[0]);
    }

    return 0;
}