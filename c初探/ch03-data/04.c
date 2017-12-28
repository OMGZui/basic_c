#include <stdio.h>

int main(void)
{
    float f = 0.0f;
    scanf("%f", &f);
    printf("The input is %f or %e or %a.\n", f, f, f);
    //The input is 64.250000 or 6.425000e+01 or 0x1.01p+6.

    return 0;
}
