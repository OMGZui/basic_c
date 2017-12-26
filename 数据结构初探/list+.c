#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

//Node结构体
typedef struct Node
{
	int data;//数据域
	struct Node * pNext;//指针域
}NODE, * PNODE;

//函数声明
PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE pHead);

//main函数
int main(void)
{
	PNODE pHead = NULL;
	pHead =  create_list();	
	traverse_list(pHead);
	
	if(is_empty(pHead))
		printf("链表为空\n");
	else 
		printf("链表不为空\n");
	
	int len = length_list(pHead);
	printf("链表长度是：%d\n",len);
	sort_list(pHead);
	traverse_list(pHead);
}

//创建非循环单链表，头结点地址赋给pHead
PNODE create_list(void)
{
	int len;
	int i;
	int val;
	//分配头结点
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("分配失败!\n");
		exit(-1);
	}
	//尾结点
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	
	printf("请输入个数：len = ");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		printf("请输入第%d个节点值：",i+1);
		scanf("%d",&val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("分配失败!\n");
			exit(-1);
		}
		//pNew挂到尾结点后面
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
	
	while(NULL != p)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

//判断链表是否为空
bool is_empty(PNODE pHead)
{
	if(NULL == pHead->pNext)
		return true;
	else
		return false;
}

//获取链表长度
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	
	while(NULL != p)
	{
		len++;
		p = p->pNext;
	}
	return len;
}

//排序
void sort_list(PNODE pHead)
{
	int i,j,t;
	int len = length_list(pHead);
	PNODE p,q;
	
	for(i=0,p=pHead->pNext;i<len;i++,p=p->pNext)
	{
		for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
		{
			if(p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}






