#include <stdio.h>
#include <stdarg.h>

// 可变参数  真鸡肋
float avg(int n_values, ...)
{
    va_list va_args;
    int count;
    float sum = 0;
    va_start(va_args, n_values);
    for (count = 0; count < n_values; count++)
    {
        sum += va_arg(va_args, int);
        printf("%.2f\n", sum);
    }
    va_end(va_args);

    return sum / n_values;
}

int main(int argc, char const *argv[])
{
    printf("%.2f", avg(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    return 0;
}
