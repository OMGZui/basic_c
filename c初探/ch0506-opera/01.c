#include <stdio.h>

int main(void)
{
    // const int PER_HOUR_MINUTES = 60;
    // int minutes = 0;

    // printf("Please input minutes(<=0 to quit): ");
    // scanf("%d", &minutes);
    // while (minutes > 0)
    // {
    //     printf("%d minutes is equal to %d hour, %d minutes.\n", minutes,
    //             minutes / PER_HOUR_MINUTES, minutes % PER_HOUR_MINUTES);
    //     printf("Please input minutes(<=0 to quit): ");
    //     scanf("%d", &minutes);
    // }

    const int HOUR_HAS_MINUTES = 60;

    int minutes;

    while (minutes > 0)
    {
        printf("请输入分钟数，如果小于等于0则退出：");
        scanf("%d", &minutes);
        printf("%d分钟=%d小时+%d分钟\n", minutes, minutes / HOUR_HAS_MINUTES, minutes % HOUR_HAS_MINUTES);
    }
    return 0;
}
