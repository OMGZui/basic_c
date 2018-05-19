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

List create(int);

int main(void)
{
    int n= 41; // 41个人
    int m = 3;  // 第3个人死亡
    int i;

    List p = create(n);
    List temp;

    m = m % n;

    while (p != p->next)
    {
        for (i = 1; i < m - 1; i++)
        {
            p = p->next;
        }

        printf("%d->", p->next->data);
        // 删除节点
        temp = p->next;
        p->next = temp->next;
        free(temp);

        p = p->next;
    }   
    printf("%d\n", p->data);
    return 0;
}

// 创建循环链表
List create(int n)
{
    List p = NULL;
    List pNew;
    List pHead = (List)malloc(sizeof(LNode));
    int i = 1;
    // 头结点
    p = pHead;

    if (0 != n)
    {
        while (i <= n)
        {
            pNew = (List)malloc(sizeof(LNode));
            // 双向链表赋值i
            pNew->data = i++;
            p->next = pNew;
            p = pNew;
        }
        // 循环链表 最后的节点指向第一个节点
        pNew->next = pHead->next;
    }
    free(pHead);
    return pNew->next;
}