#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

void f(int, char, char, char);

int main(void)
{
    int n;
    char A = 'A';
    char B = 'B';
    char C = 'C';

    printf("请输入个数：");
    scanf("%d", &n);

    f(n, 'A', 'B', 'C');

    return 0;
}

void f(int n, char A, char B, char C)
{
    if (1 == n)
    {
        printf("编号%d从%c移到%c\n", n, A, C);
    }
    else
    {
        f(n - 1, A, C, B); // A通过C移到B
        printf("编号%d从%c移到%c\n", n, A, C);
        f(n - 1, B, A, C); // B通过A移到C
    }
}