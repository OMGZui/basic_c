#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

struct BTNode * CreateBTree();
void PreTraverseBtree(struct BTNode *);
void InTraverseBtree(struct BTNode *);
void PostTraverseBtree(struct BTNode *);



struct BTNode
{
	char data;//数据
	struct BTNode * pLchild;//左子树
	struct BTNode * pRchild;//右子树
};


int main(int argc, char *argv[]) {
	
	struct BTNode * pT = CreateBTree();
	
	//PreTraverseBtree(pT);//先序
	InTraverseBtree(pT);//中序
	//PostTraverseBtree(pT);//后序
	
	return 0;
}

//创建静态二叉树
struct BTNode * CreateBTree(void)
{
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	//A
	pA->pLchild = pB;
	pA->pRchild = pC;
	//B
	pB->pLchild = NULL;
	pB->pRchild = NULL;
	//C
	pC->pLchild = pD;
	pC->pRchild = NULL;
	//D
	pD->pLchild = NULL;
	pD->pRchild = pE;
	//E
	pE->pLchild = NULL;
	pE->pRchild = NULL;
	
	return pA;
	
}

//先序
void PreTraverseBtree(struct BTNode * pT)
{
	if(NULL != pT)
	{
		printf("%c\n",pT->data);
		
		if(NULL != pT->pLchild)
		{
			PreTraverseBtree(pT->pLchild);
		}
		
		if(NULL != pT->pRchild)
		{
			PreTraverseBtree(pT->pRchild);
		}
	}
	return;
}


//中序
void InTraverseBtree(struct BTNode * pT)
{
	if(NULL != pT)
	{
		
		
		if(NULL != pT->pLchild)
		{
			InTraverseBtree(pT->pLchild);
		}
		
		printf("%c\n",pT->data);
		
		if(NULL != pT->pRchild)
		{
			InTraverseBtree(pT->pRchild);
		}
	}
	return;
}

//后序
void PostTraverseBtree(struct BTNode * pT)
{
	if(NULL != pT)
	{
		if(NULL != pT->pLchild)
		{
			PostTraverseBtree(pT->pLchild);
		}
		
		if(NULL != pT->pRchild)
		{
			PostTraverseBtree(pT->pRchild);
		}
	
		printf("%c\n",pT->data);
	}
	return;
}

