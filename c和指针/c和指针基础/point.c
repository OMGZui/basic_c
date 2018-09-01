#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 112;
    int b = -1;
    float c = 3.14;
    int *d = &a;
    float *e = &c;

    printf("a=%d b=%d c=%.2f d=%p e=%p *d=%d *e=%.2f", a, b, c, d, e, *d, *e);
    return 0;
}
