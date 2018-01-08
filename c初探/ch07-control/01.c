#include <stdio.h>

int main(void)
{
    char ch;
    int blank_cnt = 0;
    int line_cnt = 1;
    int char_cnt = 0;

    while ((ch = getchar()) != '#')
    {
        switch (ch)
        {
            case ' ':
                blank_cnt++;
                break;
            case '\n':
                line_cnt++;
            default:
                char_cnt++;
        }
    }
    printf("blank: %d\nline: %d\nchar: %d\n", blank_cnt, line_cnt, char_cnt);

    return 0;
}
