#include <stdio.h>

int main(void)
{

    double arr[10] = {1, 2, 3};
    double *p = arr;

    printf("%p\n", p);
    printf("%p\n", p + 1);

    return 0;
}
