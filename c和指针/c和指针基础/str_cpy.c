#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 字符串复制
char *str_cpy(char *dst, const char *str)
{
    // 断言，检测传入参数的合法性
    assert((dst != NULL) && (str != NULL));
    // 临时指针
    char *tmp = dst;
    // 这里后面的分号意思是等到括号中条件结束
    while ((*tmp++ = *str++) != '\0');
    return dst;
}

// 可见有多麻烦，复制个字符串，像我大PHP，直接一把梭
int main(int argc, char const *argv[])
{
    char *str = "hello";
    char new_str[10];
    str_cpy(new_str, str);
    printf("%s\n", new_str);

    char *new_string = malloc(strlen(str)+1);
    if(new_string != NULL)
    {
        strcpy(new_string, str);
    }
    printf("%s\n", new_string);
    return 0;
}
