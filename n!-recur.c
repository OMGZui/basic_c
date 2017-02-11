#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

long f(long n)
{
	if(1 == n)
		return 1;
	else
		return f(n-1) * n;
}

int main(int argc, char *argv[]) 
{
	long n;
	printf("请输入一个数字：");
	printf("n = ");
	scanf("%ld",&n);
	
	printf("%ld\n",f(n));
	
	return 0;	
}