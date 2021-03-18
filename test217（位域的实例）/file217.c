#include <stdio.h>
int main()
{
    struct bs
	{
		unsigned a:1;             //a占用1个二进制位
		unsigned b:3;             //b占用3个二进制位
		unsigned c:4;             //c占用4个二进制位
	}
    bit,*pbit;             //定义bs型变量bit与bs型指针*pbit
	bit.a=1;          //为位域赋值
	bit.b=7;
	bit.c=15;
	printf("%d,%d,%d/n",bit.a,bit.b,bit.c);           //以整型格式输出3个位域的内容
	pbit=&bit;           //把位域变量bit的地址赋给指针变量pbit
	pbit->a=0;              //用指针方式给位域a重新赋值
	pbit->b&=3;     //相当于pbit->b=pbit->b+3
	pbit->c|=1;       //相当于pbit->c=pbit->+1
	printf("%d,%d,%d/n",pbit->a,pbit->b,pbit->c);
	return 0;
}