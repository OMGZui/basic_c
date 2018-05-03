#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

typedef struct Node *List;
typedef struct Node LNode;

struct Node
{
    int data;
    List next;
};

List init();
void show(List);
bool is_empty(List);
int length(List);

int main(void)
{
    int i;
    List pHead = init();
    if (!is_empty(pHead))
    {
        show(pHead);
    }
    printf("链表长度为：%d\n", length(pHead));


    return 0;
}

// 初始化
List init()
{
    int val, len;
    int i = 0;
    // 头结点
    List pHead = (List)malloc(sizeof(LNode));
    // 尾结点
    List pTail = pHead;
    pTail->next = NULL;

    // 单链表长度
    printf("请输入一个链表长度：");
    scanf("%d", &len);
    // 尾插法
    while (i < len)
    {
        // 新结点
        List pNew = (List)malloc(sizeof(LNode));
        printf("第%d个结点值:", i + 1);
        scanf("%d", &val);
        pNew->data = val;
        // 新的尾结点
        pTail->next = pNew;
        pNew->next = NULL;

        pTail = pNew;
        i++;
    }
    return pHead;
}

// 展示
void show(List pHead)
{
    List p = pHead->next;
    printf("单链表为：");
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 是否是空
bool is_empty(List pHead)
{
    if (pHead->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 链表长度
int length(List pHead)
{
    if (is_empty(pHead))
    {
        printf("空链表\n");
        exit(-1);
    }
    int len = 0;
    List p = pHead->next;
    while (p != NULL)
    {
        ++len;
        p = p->next;
    }
    return len;
}