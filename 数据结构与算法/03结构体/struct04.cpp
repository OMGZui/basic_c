#include <stdio.h>
#include <string.h>

void g(struct Student *);
void f(struct Student);
void f2(struct Student *);

struct Student
{
    int sid;
    char name[200];
    int age;
};

int main(void)
{
    struct Student stu;
    g(&stu); // 赋值
    f(stu); // 输出  不推荐，耗内存，传了4+200+4=208个字节
    f2(&stu); // 输出 4字节

    return 0;
}

void g(struct Student * pstu)
{
    (*pstu).sid = 3;
    strcpy(pstu->name, "chensw");
    pstu->age = 27;
}

void f(struct Student stu)
{
    printf("你的学号是：%d\n", stu.sid);
    printf("你的名字是：%s\n", stu.name);
    printf("你的年龄是：%d\n", stu.age);
}

void f2(struct Student *pstu)
{
    printf("你的学号是：%d\n", pstu->sid);
    printf("你的名字是：%s\n", pstu->name);
    printf("你的年龄是：%d\n", pstu->age);
}
