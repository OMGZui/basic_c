#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char message[100] = "";
    strncpy(message, "Hello ", 10);
    strcat(message, "Jim");
    strcat(message, ", how are you?");
    printf("%s\n", message);
    return 0;
}
