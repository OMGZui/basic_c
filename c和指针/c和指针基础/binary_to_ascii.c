#include <stdio.h>

// 递归通过堆栈实现
void binary_to_ascii(unsigned int value)
{
    printf("%d  ", value);
    unsigned int tmp;
    tmp = value / 10;
    if (tmp != 0)
    {
        binary_to_ascii(tmp);
    }
    printf("'%c'  ", value % 10 + '0');
}

int main(int argc, char const *argv[])
{
    int value = 4276;
    binary_to_ascii(value);
    return 0;
}
