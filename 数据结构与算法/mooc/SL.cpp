#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

typedef struct Node * List; // 链表别名
struct Node {
    int *elem; //数组中第一个元素
    int len; //数组的长度
    int valids; //数组中有效个数
};

typedef struct Node LNode;


int main(void)
{
    return 0;
}