#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int arr[5] = {1, 2, 3, 4, 5};
    int len = 5, i;

    int *pArr = (int *)malloc(sizeof(int) * len);

    for (i = 0; i < len; i++)
    {
        *(pArr + i) = arr[i];
    }

    for (i = 0; i < len; i++)
    {
        printf("%d  ", *(pArr + i));
    }

    printf("%p ", pArr);
    printf("%p\n", pArr+1);

    free(pArr);
    return 0;
}