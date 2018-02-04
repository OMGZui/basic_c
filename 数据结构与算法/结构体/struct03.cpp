#include <stdio.h>
#include <string.h>

void g(struct Student *);

struct Student
{
    int sid;
    char name[200];
    int age;
};

int main(void)
{
    struct Student stu;
    g(&stu);

    printf("你的学号是：%d\n", stu.sid);
    printf("你的名字是：%s\n", stu.name);
    printf("你的年龄是：%d\n", stu.age);
    return 0;
}

void g(struct Student * pstu)
{
    (*pstu).sid = 3;
    strcpy(pstu->name, "chensw");
    pstu->age = 27;
}
