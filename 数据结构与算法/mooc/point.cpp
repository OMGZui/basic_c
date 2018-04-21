#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

// 连续链表 头结点、长度

typedef struct LNode *List;
struct LNode
{
    int *elem;
    int len;
};
typedef struct LNode Node;

List create();
void traverse(List);

int main(void)
{
    List L;
    L = create();
    traverse(L);
    return 0;
}

List create()
{
    int i, val, len;
    int *p;
    List L;
    L = (List)malloc(sizeof(Node));
    L->elem = (int *)malloc(sizeof(int));
    L->len = 0;
    printf("请输入一个正整数：");
    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {   
        printf("请输入第%d个节点值：", i+1);
        scanf("%d", &val);
        *(L->elem + i) = val;
        L->len++;
    }
    return L;
}

void traverse(List L)
{
    int i, len;
    len = L->len;
    for (i = 0; i < len; i++)
    {
        printf("%d\n", *(L->elem + i));
    }
}
