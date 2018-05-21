#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <stdbool.h>

#define DataType int
#define Len 10

struct HashNode
{
    DataType data;
    int isNull;
};

typedef struct HashNode HashTable;

void init();
int getAddress(DataType);
int insert(DataType);
int find(DataType);

HashTable hashTable[Len];

// 将关键字序列{7, 8, 30, 11, 18, 9, 14}散列存储到散列表中。
// 散列表的存储空间是一个下标从0开始的一维数组，长度为10，即{0, 1,2, 3, 4, 5, 6, 7, 8, 9}。
// 散列函数为： H(key) = (key * 3) % 7，处理冲突采用线性探测再散列法。
int main(void)
{
    int key[] = {7, 8, 30, 11, 18, 9, 14};
    int i;
    int address;
    init();
    for (i = 0; i < 7; i++)
    {
        insert(key[i]);
    }

    for (i = 0; i < 7; i++)
    {
        address = find(key[i]);
        printf("key:%d\t address:%d\n", key[i], address);
    }
    return 0;

// key:7	 address:0
// key:8	 address:3
// key:30	 address:6
// key:11	 address:5
// key:18	 address:7
// key:9	 address:8
// key:14	 address:1
}

// 哈希表初始化
void init()
{
    int i;
    for (i = 0; i < Len; i++)
    {
        hashTable[i].isNull = 1;
    }
}

int getAddress(DataType key)
{
    // 散列函数H(key) = (key * 3) % 7
    return key * 3 % 7;
}

int insert(DataType key)
{
    int address = getAddress(key);

    if (hashTable[address].isNull == 1)
    {
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    else
    {
        // 冲突
        while (hashTable[address].isNull == 0 && address < Len)
        {
            address++;
        }
        if (address == Len)
        {
            return -1;
        }
        hashTable[address].data = key;
        hashTable[address].isNull = 0;
    }
    return 0;
}

int find(DataType key)
{
    int address = getAddress(key);
    while (!(hashTable[address].isNull == 0 && hashTable[address].data == key && address < Len))
    {
        address++;
    }

    if (address == Len)
    {
        return -1;
    }
    return address;
}
