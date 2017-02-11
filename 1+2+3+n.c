#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>


int f(int n)
{
	if(1 == n)
		return 1;
	else
		return f(n-1) + n;
}


int main(int argc, char *argv[]) 
{
	int n;
	printf("请输入一个数字：");
	printf("n = ");
	scanf("%d",&n);
	
	printf("结果是：%d\n",f(n));
	
	return 0;
}