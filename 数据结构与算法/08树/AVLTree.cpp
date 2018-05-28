#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义函数变量需要带()
#define HEIGHT(p) (((p) == NULL) ? 0 : ((AVLTree(p))->height))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef int Type;
typedef struct AVLTreeNode *AVLTree;
typedef struct AVLTreeNode Node;

int avltree_height(AVLTree);

struct AVLTreeNode
{
    Type key;
    int height;
    AVLTree left;
    AVLTree right;
};

// 平衡二叉树，树的高度差最多为1
int main(int avgc, char **acgv)
{
    return 0;
}

// 树的高度
int avltree_height(AVLTree tree)
{
    return HEIGHT(tree);
}
