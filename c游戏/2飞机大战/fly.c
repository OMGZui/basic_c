#include <stdio.h>
#include <stdlib.h> // system()

int main(void)
{
    int i, j;
    int x = 5;
    int y = 10;
    char input;

    while (1)
    {
        system("clear"); // 清屏函数
        // 输出小球上面的空行
        for (i = 0; i < x; i++)
        {
            printf("\n");
        }
        // 输出小球左边的空格
        for (j = 0; j < y; j++)
        {
            printf(" ");
        }
        printf("*"); // 输出小球o
        printf("\n");

        scanf("%c", &input); // 根据用户的不同输入来移动
        if (input == 'a')
            y--;
        if (input == 'd')
            y++;
        if (input == 'w')
            x--;
        if (input == 's')
            x++;
    }
}
