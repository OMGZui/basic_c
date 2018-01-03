#include <stdio.h>

int main(void)
{
    char first_name[3];
    char last_name[4];

    printf("请输入你的名字：");
    scanf("%s %s", first_name, last_name);
    printf("%s%s\n", last_name, first_name);

    return 0;
}
