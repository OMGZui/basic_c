#include <stdio.h>

void show_arr(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d  ", p[i]);
    }
    printf("\n");
}

void show_point(int *p, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d  ", *(p + i));
    }
    printf("\n");
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    show_arr(arr, 5);
    show_point(arr, 5);
    return 0;
}