#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define PRAISE "You are an extraordinary being."
int main(void)
{
    char name[40];

    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %lu letters occupies %lu memory cells.\n",
            strlen(name), sizeof(name));
    printf("The phrase of praise has %zd letters ",
            strlen(PRAISE));
    printf("and occupies %lu memory cells.\n", sizeof(PRAISE));

    return 0;
}
