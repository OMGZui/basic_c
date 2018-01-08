#include <stdio.h>
#include <ctype.h>

#define SPACE ' ' 

int main(void)
{
    char ch;

    ch = getchar();
    while (ch != '\n')
    {
        // if (ch == SPACE){
        // 不是字母直接输出自己
        if (!isalpha(ch)){
            putchar(ch);
        }else{
            putchar(ch + 1);
        }
        ch = getchar();
    }

    putchar(ch);

    return 0;
}
