#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen("test.txt", "w+");
    fprintf(f, "%d %s", argc, argv[0]);
    fclose(f);
    return 0;
}
