#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

typedef struct LNode *List;
struct LNode
{
    int Data;
    List PNext;
};
typedef struct LNode Node;

List create_list(void);
void traverse_list(List);
int length_list(List);
bool insert_list(List, int, int);
bool delete_list(List, int, int *);
void sort_list(List);

int main(void)
{
    List pHead;
    int val;
    // 创建单链表并返回头结点
    pHead = create_list();
    traverse_list(pHead);
    printf("%d\n", length_list(pHead));

    insert_list(pHead, 2, 100);
    traverse_list(pHead);
    printf("%d\n", length_list(pHead));

    delete_list(pHead, 3, &val);
    printf("删除了%d\n", val);
    traverse_list(pHead);
    printf("%d\n", length_list(pHead));

    sort_list(pHead);
    traverse_list(pHead);
    printf("%d\n", length_list(pHead));
}

List create_list(void)
{
    int len, i, val;

    // 头结点
    List pHead = (List)malloc(sizeof(Node));

    // 尾结点
    List pTail = pHead;
    pTail->Data = NULL;

    printf("请输入一个正整数：");
    scanf("%d", &len);

    for (i = 1; i <= len; i++)
    {
        printf("请输入第%d个节点值：", i);
        scanf("%d", &val);

        List pNew = (List)malloc(sizeof(Node));

        pNew->Data = val;
        pTail->PNext = pNew;
        pNew->PNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

//遍历链表
void traverse_list(List pHead)
{
    List p = pHead->PNext;

    while (NULL != p)
    {
        printf("%d ", p->Data);
        p = p->PNext;
    }
    printf("\n");
    return;
}

int length_list(List pHead)
{
    List p = pHead->PNext;
    int len = 0;
    while (NULL != p)
    {
        len++;
        p = p->PNext;
    }
    return len;
}

bool insert_list(List pHead, int pos, int val)
{
    List p = pHead;
    int i = 0;

    // 拿到第pos个节点
    while (NULL != p->PNext && i < pos - 1)
    {
        p = p->PNext;
        i++;
    }

    if (i > pos - 1 || p == NULL)
    {
        return false;
    }

    List pNew = (List)malloc(sizeof(Node));
    pNew->Data = val;
    List _p = p->PNext;
    p->PNext = pNew;
    pNew->PNext = _p;

    return true;
}

bool delete_list(List pHead, int pos, int *pVal)
{
    List p = pHead;
    int i = 0;
    // 拿到第pos个节点
    while (NULL != p->PNext && i < pos - 1)
    {
        p = p->PNext;
        i++;
    }

    if (i > pos - 1 || p == NULL)
    {
        return false;
    }

    *pVal = p->PNext->Data;
    List _p = p->PNext;
    p->PNext = p->PNext->PNext;
    free(_p);
    _p = NULL;

    return true;
}

void sort_list(List pHead)
{
    int i, j, t;
    int len = length_list(pHead);
    List p, q;

    for (i = 0, p = pHead->PNext; i < len; i++, p = p->PNext)
    {
        for (j = i + 1, q = p->PNext; j < len; j++, q = q->PNext)
        {
            if (p->Data > q->Data)
            {
                t = p->Data;
                p->Data = q->Data;
                q->Data = t;
            }
        }
    }
    return;
}