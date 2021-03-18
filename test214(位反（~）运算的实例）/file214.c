#include <stdio.h>
int main()
{
	unsigned short int i=7;         //进二进制运算式用无符号数变量好点
	printf("%d\n",~i);     //按位取反，用二进制输出
	printf("%x\n",~i);     //按位取反，用十六进制输出
	return 0;
}