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
void traverse_list(PNODE);
bool is_empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int *);
void sort_list(PNODE);

//main函数
int main(void)
{
	PNODE pHead = NULL;
	int val;
	int pos = 4;
	pHead =  create_list();	
	traverse_list(pHead);
	// //删除
	// if(delete_list(pHead,pos,&val))
	// {
	// 	printf("第%d个节点被删除，元素为：%d\n",pos,val);
	// }
	// else 
	// {
	// 	printf("删除失败\n");
	// }
	// traverse_list(pHead);
	
//	//插入
//	insert_list(pHead,4,23);
//	traverse_list(pHead);

	//是否为空
	if(is_empty(pHead))
		printf("链表为空\n");
	else 
		printf("链表不为空\n");

//	//链表长度
//	int len = length_list(pHead);
//	printf("链表长度是：%d\n",len);

//  //链表排序
//	sort_list(pHead);
//	traverse_list(pHead);
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
	
	for(i=0,p=pHead->pNext; i<len; i++,p=p->pNext)
	{
		for(j=i+1,q=p->pNext; j<len; j++,q=q->pNext)
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

//插入 第pos个节点前插入新结点，值为val
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	
	while(NULL!=p && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	
	if(i>pos-1 || NULL==p)
		return false;
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL == pNew)
	{
		printf("动态分配内存失败！\n");
		exit(-1);
	}
	
	pNew->data = val;
	//临时分配的节点_q
	PNODE _q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = _q;
	
	return true;
	
}

//删除第pos个节点，值为*pVal
bool delete_list(PNODE pHead,int pos,int * pVal)
{
	int i = 0;
	PNODE p = pHead;
	
	while(NULL!=p->pNext && i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	
	if(i>pos-1 || NULL==p->pNext)
		return false;
	//临时分配的节点_q
	PNODE _q = p->pNext;
	*pVal = _q->data;
	
	p->pNext = p->pNext->pNext;
	free(_q);
	_q = NULL;
	
	return true;
}


