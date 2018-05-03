#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

typedef struct Node ArrayNode;
typedef struct Node *List;

struct Node
{
    int *pElem; //数组中第一个元素
    int len;    //数组的长度
    int valids; //数组中有效个数
};

void init(List, int);
bool is_empty(List);
bool is_full(List);
bool append(List, int);
void show(List);
bool insert(List, int, int);
bool remove(List, int, int *);

int main(void)
{
    // 声明一个类型为Node的结构体变量arr
    ArrayNode arr;
    int val;
    // 初始化
    init(&arr, 10);
    // 追加
    for (int i = 1; i < 8; i++)
    {
        append(&arr, i);
    }
    show(&arr);
    printf("当前数组个数：%d\n", arr.valids);
    if (append(&arr, 11))
    {
        show(&arr);
    }
    if (append(&arr, 12))
    {
        show(&arr);
    }
    // 插入
    if (insert(&arr, 4, 100))
    {
        show(&arr);
    }
    if (insert(&arr, -1, -100))
    {
        show(&arr);
    }
    if (insert(&arr, 100, 1000))
    {
        show(&arr);
    }
    // 删除
    if (remove(&arr, 4, &val))
    {
        printf("删除的值是：%d\n", val);
        show(&arr);
    }
    if (remove(&arr, 100, &val))
    {
        printf("删除的值是：%d\n", val);
        show(&arr);
    }
    if (remove(&arr, -1, &val))
    {
        printf("删除的值是：%d\n", val);
        show(&arr);
    }

    return 0;
}

// 判断是否为空
bool is_empty(List pArr)
{
    // 数组有效个数为0时，即为空
    if (0 == pArr->valids)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 判断是否为满
bool is_full(List pArr)
{
    // 数组有效个数为0时，即为空
    if (pArr->valids == pArr->len)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 初始化
void init(List pArr, int length)
{
    // 初始化第一个元素
    pArr->pElem = (int *)malloc(sizeof(int) * length);
    pArr->valids = 0;
    pArr->len = length;
    return;
}

// 输出
void show(List pArr)
{
    if (is_empty(pArr))
    {
        printf("数组为空\n");
    }
    else
    {
        for (int i = 0; i < pArr->valids; i++)
        {
            printf("%d  ", *(pArr->pElem + i));
        }
        printf("\n");
    }
    return;
}

// 追加值
bool append(List pArr, int val)
{
    if (is_full(pArr))
    {
        printf("数组已满\n");
        return false;
    }
    *(pArr->pElem + pArr->valids) = val;
    pArr->valids++;
    return true;
}

// 插入元素到指定位置
bool insert(List pArr, int pos, int val)
{
    int i;
    if (is_full(pArr))
    {
        printf("数组已满\n");
        return false;
    }

    if (pos > pArr->len + 1 || pos < 1)
    {
        printf("位置不合理\n");
        return false;
    }
    // 往后移到pos-1处
    for (i = pArr->valids - 1; i <= pos - 1; i--)
    {
        *(pArr->pElem + (i + 1)) = *(pArr->pElem + i);
    }
    *(pArr->pElem + (pos - 1)) = val;
    return true;
}
// 删除指定位置元素
bool remove(List pArr, int pos, int *pVal)
{
    int i;
    // 空
    if (is_empty(pArr))
    {
        printf("空数组，不能删除\n");
        return false;
    }
    // 位置错了
    if (pos < 1 || pos > pArr->len)
    {
        printf("位置不合理\n");
        return false;
    }
    *pVal = *(pArr->pElem + (pos - 1));
    // 向前移到pos-1处
    for (i = pos; i < pArr->valids; i++)
    {
        *(pArr->pElem + (i - 1)) = *(pArr->pElem + i);
    }
    pArr->valids--;
    return true;
}