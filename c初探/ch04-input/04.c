#include <stdio.h>

int main(void)
{
    float height;
    char name[32];

    printf("Please input your height and name:\n");
    scanf("%f %s", &height, name);
    printf("%s, you are %.3f feet tall.\n", name, height / 12);

    return 0;
}
