#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) 
{
	int n;
	int i;
	int sum = 1;
	
	printf("请输入一个数字：");
	printf("n = ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		sum = i * sum;
	
	printf("%d的阶乘是：%d\n",n,sum);
	
	return 0;
}