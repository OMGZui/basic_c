#include <stdio.h>

int main(void)
{
    float f;

    printf("Input a float number: ");
    scanf("%f", &f);

    printf("a.The input is %2.1f or %1.1e\n", f, f);
    printf("b.The input is %+2.3f or %1.3E\n", f, f);

    return 0;
}
