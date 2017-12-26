#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

void f(int n)
{
	if(n == 1)
		printf("Hello\n");
	else
		f(n-1);
}

int main(int argc, char *argv[]) 
{
	f(6);
	
	return 0;
}