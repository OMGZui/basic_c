#include <stdio.h>

void f(void);
void g(void);
void k(void);

void f()
{
    printf("FFFF\n");
    g();
    printf("1111\n");
}

void g()
{
    printf("GGGG\n");
    k();
    printf("2222\n");
}

void k()
{
    printf("KKKK\n");
}

int main(void)
{
    // FFFF
    // GGGG
    // KKKK
    // 2222
    // 1111
    f();
    return 0;
}