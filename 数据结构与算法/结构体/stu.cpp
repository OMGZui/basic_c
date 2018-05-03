#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[50];
    int age;
};


int main(void)
{
    struct Student st = {16, "omgzui", 24}; // st是一个变量名字，类型为struct Student

    st.sid = 18;
    printf("%d\n", st.sid);

    // pst是一个指针变量，类型为struct Student，并且指向了st的地址，struct Student *pst等价于struct Student st
    struct Student * pst = &st;
    pst->sid = 100;
    printf("%d\n", pst->sid);

    return 0;
}