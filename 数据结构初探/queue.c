#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;
}QUEUE;

//声明
void init(QUEUE *);
bool en_queue(QUEUE *,int);//入队
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool out_queue(QUEUE *,int *);//出队
bool empty_queue(QUEUE *);

int main(int argc, char *argv[]) 
{
	QUEUE Q;
	init(&Q);
	int val;
	
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	traverse_queue(&Q);
	
	if(out_queue(&Q, &val))
	{
		printf("出队成功：%d\n",val);
	}
	else
	{
		printf("出队失败\n");
	}
	traverse_queue(&Q);
	return 0;
}

//初始化
void init(QUEUE * pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
	return;
}

//队列是否满
bool full_queue(QUEUE * pQ)
{
	if((pQ->rear + 1) % 6 == pQ->front)
		return true;
	else
		return false;
}

//入队
bool en_queue(QUEUE * pQ,int val)
{
	if(full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear + 1) % 6;
		
		return true;
	}
}

//遍历
void traverse_queue(QUEUE * pQ)
{
	int i = pQ->front;
	
	while(i != pQ->rear)
	{
		printf("%d ",pQ->pBase[i]);
		i = (i+1) % 6;
	}
	printf("\n");
	
	return;
}

//队列是否为空
bool empty_queue(QUEUE * pQ)
{
	if(pQ->front == pQ->rear)
		return true;
	else
		return false;
}

//出队
bool out_queue(QUEUE * pQ, int * pVal)
{
	if(empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		 pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}
