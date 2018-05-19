#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode *Tree;
typedef struct TreeNode BiTree;
struct TreeNode
{
    char data;
    Tree Lchild;
    Tree Rchild;
};

void create(Tree *);
void visit(char, int);
void preShow(Tree, int);
void inShow(Tree, int);
void lastShow(Tree, int);

int main(void)
{
    int level = 1;
    Tree T = NULL;
    create(&T);
    // preShow(T, level);
    // inShow(T, level);
    lastShow(T, level);

    return 0;
}

// 递归创建二叉树
void create(Tree *T)
{
    char c;
    scanf("%c", &c);
    if ('0' == c)
    {
        T = NULL;
    }
    else
    {
        *T = (Tree)malloc(sizeof(BiTree));
        (*T)->data = c;
        create(&(*T)->Lchild);
        create(&(*T)->Rchild);
    }
}

// 访问
void visit(char c, int level)
{
    printf("%c位于第%d层\n", c, level);
}

// 先序遍历
void preShow(Tree T, int level)
{
    if (T)
    {
        visit(T->data, level);
        preShow(T->Lchild, level + 1);
        preShow(T->Rchild, level + 1);
    }
// AB00CD0E000
// A位于第1层
// B位于第2层
// C位于第2层
// D位于第3层
// E位于第4层
}

// 中序遍历
void inShow(Tree T, int level)
{
    if (T)
    {
        inShow(T->Lchild, level + 1);
        visit(T->data, level);
        inShow(T->Rchild, level + 1);
    }
// AB00CD0E000
// B位于第2层
// A位于第1层
// D位于第3层
// E位于第4层
// C位于第2层
}

// 后序遍历
void lastShow(Tree T, int level)
{
    if (T)
    {
        lastShow(T->Lchild, level + 1);
        lastShow(T->Rchild, level + 1);
        visit(T->data, level);
    }
// AB00CD0E000
// B位于第2层
// E位于第4层
// D位于第3层
// C位于第2层
// A位于第1层
}