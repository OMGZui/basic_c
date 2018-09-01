#include <stdio.h>

#define SIZE 10

// 数组形式
void print_arr(int arr[])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", arr[i]);
    }
}

// 指针形式
void print_point(int *arr)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", *(arr + i));
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_arr(arr);
    printf("\n");
    print_point(arr);
    return 0;
}
