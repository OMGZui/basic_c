#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[200];
    int age;
};

int main(void)
{

    // struct Student stu = {1, "shengj", 25};
    struct Student stu;
    stu.sid = 2;
    // stu.name = "wangm"; // error 不能直接赋值
    strcpy(stu.name, "wangm");
    stu.age = 26;

    printf("你的学号是：%d\n", stu.sid);
    printf("你的名字是：%s\n", stu.name);
    printf("你的年龄是：%d\n", stu.age);

    return 0;
}
