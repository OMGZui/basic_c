#include <stdio.h>

int f(int);

int main(void)
{
    int n;
    printf("请输入一个数：");
    scanf("%d", &n);
    printf("%d\n", f(n));
    return 0;
}

int f(int n)
{
    if (1 == n)
    {
        return 1;
    }
    return f(n - 1) + n;
}