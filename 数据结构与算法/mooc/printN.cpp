#include <stdio.h>
#include <time.h>

void printN1(int);
void printN2(int);

int main(void)
{
    clock_t start, stop;

    int N;
    printf("请输入一个整数：");
    scanf("%d", &N);
    start = clock();
    // printN1(N);
    printN2(N);
    stop = clock();
    printf("运行了%f秒\n", (float)(stop - start) / CLOCKS_PER_SEC);
    return 0;
}

// 循环和递归说明  空间有关
// 计数器说明 时间有关

// 循环
void printN1(int N)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }
}

// 递归
void printN2(int N)
{
    if (N)
    {
        printN2(N - 1);
        printf("%d\n", N);
    }
}