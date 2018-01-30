#include <stdio.h>
#include <stdlib.h> // system()
#include <unistd.h> // sleep()

// https://zhuanlan.zhihu.com/p/24633092
int main(void)
{
    // 初始化值
    int i, j;
    int x = 5, y = 10;

    int velocity_x = 1;
    int velocity_y = 1;
    int left = 0;
    int right = 20;
    int top = 0;
    int bottom = 10;

    while (1)
    {
        x = x + velocity_x;
        y = y + velocity_y;
        //清屏函数
        system("clear");
        //输出小球上面的空行
        for (i = 0; i < x; i++)
        {
            printf("\n");
        }
        //输出小球左边的空格
        for (j = 0; j < y; j++)
        {
            printf(" ");
        }
        printf("o");
        printf("\n");
        // 0.5秒
        usleep(500000);

        if ((x == top) || (x == bottom))
        {
            velocity_x = -velocity_x;
        }
        if ((y == left) || (y == right))
        {
            velocity_y = -velocity_y;
        }
    }

    return 0;
}
