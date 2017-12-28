#include <stdio.h>

int main(void)
{
    unsigned short age = 0;
    const unsigned int per_year_seconds = 3.156e7;

    scanf("%hu", &age);
    
    printf("Your age is %hu, which is equal to %u seconds.\n", age, age * per_year_seconds);

    return 0;
}
