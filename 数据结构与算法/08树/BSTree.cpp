#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define TBL_SIZE(a) ((sizeof(a)) / (sizeof(a[0])))
int arr[] = {1, 5, 4, 3, 2, 6};

typedef int Type;
typedef struct BSTreeNode *BSTree;
typedef struct BSTreeNode Node;

BSTree create_bstree_node(Type, BSTree, BSTree, BSTree);
BSTree bstree_insert(BSTree, BSTree);
BSTree insert_bstree(BSTree, Type);
void print_bstree(BSTree, Type, int);
void destroy_bstree(BSTree);
void preorder_bstree(BSTree);
void inorder_bstree(BSTree);
void postorder_bstree(BSTree);
BSTree bstree_search(BSTree, Type);
BSTree bstree_maximum(BSTree);
BSTree bstree_minimum(BSTree);

struct BSTreeNode
{
    Type key;      //键值
    BSTree left;   //左孩子
    BSTree right;  //右孩子
    BSTree parent; //父结点
};

// 二叉查找树
int main(int argc, char **argv)
{

    int i;
    int ilen = TBL_SIZE(arr);
    BSTree root = NULL;
    BSTree search;

    for (i = 0; i < ilen; i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }
    printf("\n前序遍历: ");
    preorder_bstree(root);
    printf("\n中序遍历: ");
    inorder_bstree(root);
    printf("\n后序遍历: ");
    postorder_bstree(root);
    printf("\n");

    print_bstree(root, root->key, 0);

    search = bstree_search(root, 5);
    printf("该结点为%d，左孩子为：%d，右孩子为：%d，父结点为%d\n", search->key, search->left->key, search->right->key, search->parent->key);

    printf("最大值：%d\n", bstree_maximum(root)->key);
    printf("最小值：%d\n", bstree_minimum(root)->key);

    destroy_bstree(root);
    return 0;
}

// 新建结点并插入二叉树
BSTree insert_bstree(BSTree tree, Type key)
{
    BSTree z;
    z = create_bstree_node(key, NULL, NULL, NULL);

    // 如果新建结点失败，则返回
    if (z == NULL)
    {
        return tree;
    }

    return bstree_insert(tree, z);
}

// 先序遍历
void preorder_bstree(BSTree tree)
{
    if (NULL != tree)
    {
        printf("%d ", tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}

// 中序遍历
void inorder_bstree(BSTree tree)
{
    if (NULL != tree)
    {
        preorder_bstree(tree->left);
        printf("%d ", tree->key);
        preorder_bstree(tree->right);
    }
}

// 后序遍历
void postorder_bstree(BSTree tree)
{
    if (NULL != tree)
    {
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
        printf("%d ", tree->key);
    }
}

/**
 * 打印二叉树 
 * direction 0/根结点 -1/父结点的左孩子 1/父结点的右孩子
 */
void print_bstree(BSTree tree, Type key, int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)
        {
            printf("%2d是根结点\n", tree->key);
        }
        else
        {
            printf("%2d是%d的%s孩子\n", tree->key, key, direction == 1 ? "右" : "左");
        }
        print_bstree(tree->left, tree->key, -1);
        print_bstree(tree->right, tree->key, 1);
    }
}

// 销毁二叉树
void destroy_bstree(BSTree tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->left != NULL)
    {
        destroy_bstree(tree->left);
    }
    if (tree->right != NULL)
    {
        destroy_bstree(tree->right);
    }
    free(tree);
}

// 创建并返回二叉树结点
BSTree create_bstree_node(Type key, BSTree left, BSTree right, BSTree parent)
{
    BSTree p = (BSTree)malloc(sizeof(Node));
    if (NULL == p)
    {
        return NULL;
    }

    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;

    return p;
}

// 将结点插入到二叉树中
BSTree bstree_insert(BSTree tree, BSTree z)
{
    BSTree y = NULL;
    BSTree x = tree;

    // 查找z的插入位置
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    z->parent = y;
    if (NULL == y)
    {
        tree = z;
    }
    else if (z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    return tree;
}

// 递归查找
BSTree bstree_search(BSTree tree, Type key)
{
    if (NULL == tree || key == tree->key)
    {
        return tree;
    }

    if (key < tree->key)
    {
        return bstree_search(tree->left, key);
    }
    else
    {
        return bstree_search(tree->right, key);
    }
}

// 最大值
BSTree bstree_maximum(BSTree tree)
{
    if(tree->right == NULL)
    {
        return tree;
    }

    // while(tree->right != NULL)
    // {
    //     tree = tree->right;
    // }

    // return tree;

    return bstree_maximum(tree->right);
}

// 最小值
BSTree bstree_minimum(BSTree tree)
{
    if(tree->left == NULL)
    {
        return tree;
    }

    // while(tree->left != NULL)
    // {
    //     tree = tree->left;
    // }
    
    // return tree; 
    return bstree_minimum(tree->left);
}
