#include<stdio.h>

void f(int *);

int main(void)
{

    int i = 10;
    f(&i);
    printf("%d\n",i);

    return 0;
}


void f(int *x) // *x是形参
{
    *x = 100;
}
