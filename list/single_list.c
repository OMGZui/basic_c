
// 单链表

// 引用库
#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>


// 头结点结构体
typedef struct Node
{
    int data; // 数据域
    struct Node * pNext; // 指针域
}NODE, * PNODE;


//函数声明
PNODE create_list(void);
void traverse_list(PNODE);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);

// main() 函数
int main(void)
{
    PNODE pHead = NULL;

    pHead = create_list();
    
    traverse_list(pHead);
}

// 创建非循环单链表，头结点地址赋给pHead
PNODE create_list(void)
{
    int len;
    int i;
    int val;

    // 分配头结点
    PNODE pHead = (PNODE) malloc(sizeof(NODE));

    if(NULL == pHead)
	{
		printf("分配失败!\n");
		exit(-1);
    }
    
    //尾结点
	PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入个数：len = ");
    scanf("%d", &len);

    for (i = 0; i < len; i++)
    {
        printf("请输入第%d个节点值：", i + 1);
        scanf("%d", &val);

        // 新结点
        PNODE pNew = (PNODE) malloc(sizeof(NODE));
        if (NULL == pNew)
        {
            printf("分配失败!\n");
            exit(-1);
        }
        //pNew结点挂到尾结点后面
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }

    return pHead;
}

//遍历链表
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
    return;
}
