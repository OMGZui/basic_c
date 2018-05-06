#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

#define LEN 6

typedef struct Queue LQueue;
typedef struct Queue *PQueue;

struct Queue
{
    int *pBase;
    int front;
    int rear;
};

void init(PQueue);
bool enqueue(PQueue, int);
bool dequeue(PQueue, int *);
void show(PQueue);
bool is_full(PQueue);
bool is_empty(PQueue);

int main(void)
{
    int val;
    LQueue queue;
    // 初始化
    init(&queue);
    //入队
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    show(&queue);
    // 出队
    if(dequeue(&queue,&val))
    {
        printf("出队元素是：%d\n", val);
    }
    show(&queue);
    printf("插入元素：");
    scanf("%d", &val);
    enqueue(&queue, val);
    show(&queue);

    return 0;
}

// 初始化
void init(PQueue queue)
{
    queue->pBase = (int *)malloc(sizeof(int) * LEN); // 数组第一个元素
    queue->front = 0;                                // 队头
    queue->rear = 0;                                 // 队尾
    return;
}

// 入队
bool enqueue(PQueue queue, int val)
{
    if (is_full(queue))
    {
        return false;
    }
    else
    {
        // 队尾指向下一个位置，因为是循环队列，使用求余计算位置
        queue->pBase[queue->rear] = val;
        queue->rear = (queue->rear + 1) % LEN;
        return true;
    }
}

// 满
bool is_full(PQueue queue)
{
    if ((queue->rear + 1) % LEN == queue->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 展示
void show(PQueue queue)
{
    if (is_empty(queue))
    {
        printf("空队列\n");
    }
    else
    {
        int i = queue->front;
        while (i != queue->rear)
        {
            printf("%d\n", queue->pBase[i]);
            i = (i + 1) % LEN;
        }
    }
    return;
}

// 空
bool is_empty(PQueue queue)
{
    if(queue->front == queue->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 出队
bool dequeue(PQueue queue, int *pVal)
{
    if(is_empty(queue))
    {
        printf("空队列\n");
        return false;
    }
    else
    {
        *pVal = queue->pBase[queue->front];
        queue->front = (queue->front + 1) % LEN;
        return true;
    }
}