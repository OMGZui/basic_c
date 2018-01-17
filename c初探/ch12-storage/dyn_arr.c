#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // 声明
    double *ptd;
    int max = 0;
    int number;
    int i = 0;

    puts("What is the maximum number of type double entries?");
    // 检测输入参数
    if (1 != scanf("%d", &max))
    {
        puts("Number not correctly entered -- bye.");
        exit(EXIT_FAILURE);
    }

    // 分配动态内存ptd
    ptd = (double *)malloc(max * sizeof(double));
    // 检测分配内存ptd
    if (ptd == NULL)
    {
        puts("Memory allocation failed. Goodbye.");
        exit(EXIT_FAILURE);
    }

    puts("Enter the values (q to quit):");
    while (i < max && scanf("%lf", &ptd[i]) == 1)
    {
        ++i;
        printf("Here are your %d entries:\n", number = i);
        for (i = 0; i < number; i++)
        {
            printf("%7.2f ", ptd[i]);
            // 7个数分割显示
            if (i % 7 == 6)
            {
                putchar('\n');
            }
        }
        if (i % 7 != 0)
        {
            putchar('\n');
        }
    }
    puts("Done.");
    free(ptd);

    return 0;
}
