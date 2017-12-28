#include <stdio.h>

int main(void)
{
    // float和double的范围是由指数的位数来决定的
    // float的指数位有8位，而double的指数位有11位
    // float： 
    // 1bit（符号位） 8bits（指数位） 23bits（尾数位） 
    // double： 
    // 1bit（符号位） 11bits（指数位） 52bits（尾数位） 


    unsigned int a = 4294967295; //2**32-1 4字节，32位
    int b1 = 2147483647; //-2**31~2**31-1
    int b2 = -2147483648; //-2**31~2**31-1
    float c = 3.4e38; // 2**2**8 => 2**128
   
    printf("%u + 1 = %u\n", a, a+1);
    printf("%d + 1 = %d\n", b1, b1+1);
    printf("%d - 1 = %d\n", b2, b2-1);
    printf("%e * 10 = %e\n", c, c*10);

    return 0;
}
