#include <stdio.h>

double min(double, double);

int main(void)
{
    double x = 0.0, y = 0.0;

    printf("Please enter two double:\n");
    scanf("%lf %lf", &x, &y);

    printf("Min: %.2f\n", min(x, y));

    return 0;
}

double min(double x, double y)
{
    return x > y ? y : x;
}
