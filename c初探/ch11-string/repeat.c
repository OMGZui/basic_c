#include <stdio.h>

// argc => argument count “The system uses spaces to tell when one string ends and the next begins”
// argv => argument values
int main(int argc, char *argv[])
{
    int count;
    printf("The command line has %d arguments:\n", argc -1);

    for(count = 1; count < argc; count++)
    {
        printf("%d:  %s\n", count, argv[count]);
    }
    printf("\n");

    return 0;
}
