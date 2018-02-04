#include <stdio.h>

void print();

int *p;
int i = 10;

int main(void)
{
    // 说明 *p与i是等价的, p指向了i的地址
    p = &i;
    print();
    
    i = 11;
    print();

    *p = 12;
    print();

    return 0;
}

void print()
{
    printf("%d\n", *p);
    printf("%d\n", i);
    printf("%p\n", p);
    printf("%p\n", &i);
}
