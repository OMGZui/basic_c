#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Len(array) ((sizeof(array)) / (sizeof(array[0])))

void bubble(int *, int);
void printArr(int *, int);

int main(int argc, char **agrv)
{
    int arr[] = {10, -20, 5, 99, -49, 49};
    int len = Len(arr);
    printf("排序前：");
    printArr(arr, len);

    bubble(arr, len);
    printf("排序后：");
    printArr(arr, len);
    return 0;
}

// 冒泡排序
void bubble(int *arr, int len)
{
    int i, j, temp;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

// 输出
void printArr(int *arr, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}