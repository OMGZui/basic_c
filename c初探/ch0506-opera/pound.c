#include <stdio.h>

void pound(int n);

int main(void)
{
    int times = 5;
    char ch = '!';
    float f = 6.0f;
    pound(times); //5
    pound(ch); // 33
    pound((int)f); ///6

    return 0;
}

void pound(int n)
{
    while (n-- > 0)
    {
        printf("#");
    }
    printf("\n");
}
