#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[32];
    printf("请输入你的名字：");
    scanf("%s", first_name);
    printf("\"%s\"\n", first_name);
    printf("\"%20s\"\n", first_name);
    printf("\"%-20s\"\n", first_name);
    printf("\"%*s\"\n", strlen(first_name) + 3, first_name);

    return 0;
}
