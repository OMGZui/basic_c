#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

// 结点
typedef struct Node *List;
typedef struct Node LNode;
struct Node
{
    int data;
    List next;
};

// 栈
typedef struct Stack *pStack;
typedef struct Stack LStack;
struct Stack
{
    List pTop;
    List pBase;
};

void init(pStack);
void push(pStack, int);
bool pop(pStack, int *);
void show(pStack);
bool is_empty(pStack);
void clear(pStack);

int main(void)
{
    int val;
    LStack stack;
    // 初始化
    init(&stack);
    // 压栈
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 200);
    show(&stack);
    // 出栈
    if(pop(&stack, &val))
    {
        printf("出栈的值为：%d\n", val);
    }
    show(&stack);
    push(&stack, 2000);
    show(&stack);
    // 清空
    clear(&stack);
    show(&stack);

    return 0;
}

// 初始化
void init(pStack stack)
{
    // 初始化栈顶和栈尾 同时指向一个新的地址，且地址的数据域为NULL
    stack->pTop = (List)malloc(sizeof(LNode));
    stack->pBase = stack->pTop;
    stack->pBase->data = NULL;
}

// 压栈
void push(pStack stack, int val)
{
    // 新的结点
    List pNew = (List)malloc(sizeof(LNode));
    pNew->data = val;
    // pNew指向栈顶结点
    pNew->next = stack->pTop;
    // 栈顶结点变成pNew
    stack->pTop = pNew;
}

// 展示
void show(pStack stack)
{
    if (is_empty(stack))
    {
        printf("空栈\n");
        exit(-1);
    }
    List p = stack->pTop;
    printf("栈：");
    while (p != stack->pBase)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 出栈
bool pop(pStack stack, int *pVal)
{
    if (is_empty(stack))
    {
        printf("空栈\n");
        return false;
    }
    else
    {
        List r = stack->pTop;
        *pVal = r->data;
        stack->pTop = r->next;
        free(r);
        return true;
    }
}

// 空判断
bool is_empty(pStack stack)
{
    if (stack->pTop == stack->pBase)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 清空
void clear(pStack stack)
{
    List p,q;
    if (is_empty(stack))
    {
        printf("空栈\n");
    }
    else
    {
        p = stack->pTop; // 栈顶
        q = NULL;
        while(q != stack->pBase)
        {
            q = p->next; // 栈顶的上面一个元素
            free(p);
            p = q;
        }
        stack->pTop = stack->pBase; // 空栈
    }
    return;
}