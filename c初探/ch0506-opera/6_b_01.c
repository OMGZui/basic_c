#include <stdio.h>

int main(void)
{
    char letters[26] = {0};
    int i = 0;
    // “stores the 26 lowercase letters” 存入26个字母
    for (i = 0; i < 26; i++)
    {
        letters[i] = i + 'a';
    }
    // “show the array contents” 展示26个字母
    for (i = 0; i < 26; i++)
    {
        printf("%c ", letters[i]);
    }
    printf("\n");

    return 0;
}
