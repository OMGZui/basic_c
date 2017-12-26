#include <stdio.h>

// function declarations
void butler(void);

// “all C programs begin execution with main()”
int main(void)
{
    printf("你是谁啊？\n");
    butler();

    return 0;
}

// “no arguments and has no return value”
void butler(void)
{
    printf("我是男管家\n");
}
