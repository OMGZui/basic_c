#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *env = getenv("PATH");
    printf("%s\n", env);
    return 0;
}
