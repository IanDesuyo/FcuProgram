#include <stdio.h>

void soldierCheck(float bmi);
void policeCheck(float bmi);
void hpaSuggest(float bmi);

int main()
{
    // Declare variables
    float bmi;
    float height;
    float weight;

    // Prompt user for height and weight
    printf("請輸入你的身高(公尺): ");
    scanf("%f", &height);

    printf("請輸入你的體重(公斤): ");
    scanf("%f", &weight);

    // Calculate BMI
    bmi = weight / (height * height);

    // Print Results
    printf("你的BMI為: %.2f\n", bmi);
    soldierCheck(bmi);
    policeCheck(bmi);
    hpaSuggest(bmi);

    return 0;
}

void soldierCheck(float bmi)
{
    printf("兵役: ");
    if (bmi < 16.5)
    {
        printf("免役");
    }
    else if (bmi < 17)
    {
        printf("替代役");
    }
    else if (bmi <= 31)
    {
        printf("常備役");
    }
    else if (bmi <= 31.5)
    {
        printf("替代役");
    }
    else
    {
        printf("免役");
    }
    printf("\n");
}

void policeCheck(float bmi)
{
    printf("警專體檢: ");
    if (bmi < 18 || bmi > 28)
    {
        printf("不合格");
    }
    else
    {
        printf("合格");
    }
    printf("\n");
}

void hpaSuggest(float bmi)
{
    printf("國民健康署建議: ");
    if (bmi < 18.5)
    {
        printf("「體重過輕」，需要多運動，均衡飲食，以增加體能，維持健康！");
    }
    else if (bmi < 24)
    {
        printf("恭喜！「健康體重」，要繼續保持！");
    }
    else if (bmi < 27)
    {
        printf("「體重過重」了，要小心囉，趕快力行「健康體重管理」！");
    }
    else
    {
        printf("啊～「肥胖」，需要立刻力行「健康體重管理」囉！");
    }
    printf("\n");
}