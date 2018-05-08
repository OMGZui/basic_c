#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode *Tree;
struct TreeNode
{
    char data;
    Tree Lchild;
    Tree Rchild;
};

Tree create();
void preShow(Tree);
void inShow(Tree);
void lastShow(Tree);

int main(void)
{
    Tree pTree = create();
    // preShow(pTree);
    inShow(pTree);
    // lastShow(pTree);
    return 0;
}

// 创建一颗静态二叉树
Tree create()
{
    Tree pA = (Tree)malloc(sizeof(TreeNode));
    Tree pB = (Tree)malloc(sizeof(TreeNode));
    Tree pC = (Tree)malloc(sizeof(TreeNode));
    Tree pD = (Tree)malloc(sizeof(TreeNode));
    Tree pE = (Tree)malloc(sizeof(TreeNode));

    pA->data = 'A'; // 根结点
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';

    pA->Lchild = pB;
    pA->Rchild = pC;

    pB->Lchild = pB->Rchild = NULL;

    pC->Lchild = pD;
    pC->Rchild = NULL;

    pD->Lchild = NULL;
    pD->Rchild = pE;

    pE->Lchild = pE->Rchild = NULL;

    return pA;
}

// 先序
void preShow(Tree pA)
{
    if(NULL != pA)
    {
        printf("%c\n", pA->data);

        if(NULL != pA->Lchild)
        {
            preShow(pA->Lchild);
        }

        if(NULL != pA->Rchild)
        {
            preShow(pA->Rchild);
        }
    }
    return;
}

// 中序
void inShow(Tree pA)
{
    if(NULL != pA)
    {
        if(NULL != pA->Lchild)
        {
            inShow(pA->Lchild);
        }

        printf("%c\n", pA->data);

        if(NULL != pA->Rchild)
        {
            inShow(pA->Rchild);
        }
    }
    return;
}

// 后序
void lastShow(Tree pA)
{
    if(NULL != pA)
    {
        if(NULL != pA->Lchild)
        {
            lastShow(pA->Lchild);
        }

        if(NULL != pA->Rchild)
        {
            lastShow(pA->Rchild);
        }
        printf("%c\n", pA->data);
    }
    return;
}