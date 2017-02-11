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

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;//相当于头结点
}STACK, * PSTACK;

//声明
void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK,int *);
bool empty(PSTACK);
void clear(PSTACK);

int main(int argc, char *argv[]) {
	
	STACK S;
	int val;
	
	init(&S);//目的是造出一个空栈
	push(&S,1);//压栈
	push(&S,2);
	push(&S,3);
	push(&S,4);
	push(&S,5);
	push(&S,6);
	traverse(&S);//遍历输出
//	clear(&S);//清空栈
//	traverse(&S);//遍历输出
	if(pop(&S,&val))
	{
		printf("出栈成功，元素为%d\n",val);
	}
	else
	{
		printf("出栈失败");
	}
	traverse(&S);//遍历输出
	return 0;
}

//初始化
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL == pS->pTop)
	{
		printf("分配失败!\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}
}

//压栈
void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	return;
}

//遍历
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while(p != pS->pBottom)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}

bool empty(PSTACK pS)
{
	if(pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}

//出栈，并返回出栈的值* pVal，成功则true
bool pop(PSTACK pS,int * pVal)
{
	if(empty(pS))
	{
		return false;
	}
	else
	{
		PNODE _r = pS->pTop;
		* pVal = _r->data;
		pS->pTop = _r->pNext;
		free(_r);
		_r = NULL;
		
		return true;
	}
}

//清空
void clear(PSTACK pS)
{
	if(empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = p->pNext;
		
		while (p != pS->pBottom) 
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop = pS->pBottom;
	}
	return;
}
