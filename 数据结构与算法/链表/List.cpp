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
void sort(List);
bool insert(List, int, int);

int main(void)
{
    int i;
    int pos, val;
    // 初始化
    List pHead = init();
    if (!is_empty(pHead))
    {
        show(pHead);
    }
    printf("链表长度为：%d\n", length(pHead));
    // 排序
    // sort(pHead);
    // show(pHead);
    // 插入
    printf("插入到：");
    scanf("%d", &pos);
    printf("值为:");
    scanf("%d", &val);
    if (insert(pHead, pos, val))
    {
        show(pHead);
    }

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

// 排序
void sort(List pHead)
{
    int len = length(pHead);
    int i, j, t;
    List p, q;
    for (i = 0, p = pHead->next; i < len - 1; i++, p = p->next)
    {
        for (j = i + 1, q = p->next; j < len; j++, q = q->next)
        {
            if (p->data > q->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return;
}

// 插入
bool insert(List pHead, int pos, int val)
{
    int i;

    List p = pHead;

    // 拿到第pos个位置的地址
    while (NULL != p && i < pos - 1)
    {
        p = p->next;
        i++;
    }

    if (i > pos - 1 || p == NULL)
    {
        printf("位置不符\n");
        return false;
    }

    // 需要插入的新节点
    List pNew = (List)malloc(sizeof(LNode));
    pNew->data = val;
    // pos+1位置地址
    List q = p->next;
    // pos+1位置指向了pNew
    p->next = pNew;
    // pNew指向了之前的pos+1位置地址
    pNew->next = q;

    return true;
}