#include <stdio.h>
#include <string.h>

#include "str_len.h"

int main(int argc, char const *argv[])
{
    char *str1 = "hello";
    char tmp[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char *str2 = tmp;
    char str3[] = "hello";
    char str_c[] = "hello";
    char *str4 = &str_c[0];
    printf("len1=%d\n", str_len(str1));
    printf("len1=%ld\n", strlen(str1));

    printf("len2=%d\n", str_len(str2));
    printf("len2=%ld\n", strlen(str2));

    printf("len3=%d\n", str_len(str3));
    printf("len3=%ld\n", strlen(str3));

    printf("len4=%d\n", str_len(str4));
    printf("len4=%ld\n", strlen(str4));

    return 0;
}
