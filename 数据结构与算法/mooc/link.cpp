#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // int arr[100];
    // int i;

    // for (i = 0; i < 10; i++)
    // {
    //     arr[i] = i;
    // }

    // for (i = 0; i < 10; i++)
    // {
    //     printf("%d\n", arr[i]);
    // }

    int *arr, i;

    arr = (int *)malloc(sizeof(int));

    for (i = 0; i < 10; i++)
    {
        *(arr+i) = i;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", *(arr+i));
    }
}