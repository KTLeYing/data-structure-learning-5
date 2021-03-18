#include <stdio.h>
struct byte           //定义一个位域结构
{
    unsigned char b0:1;    //表示二进制的第一位
	unsigned char b1:1;    //表示二进制的第二位
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
};
union bits                 //定义一个联合
{
	unsigned char c;            //包含无符号字符型变量成员
	struct byte bit;            //包含位域结构体成员
};
int main()
{
	union bits b;          //定义联合变量b
	int i;               
	unsigned char ch;       //定义无符号字符型变量ch
	printf("please input the number from 0 to 255:");
	scanf("%d",&ch);               //为ch赋值
	b.c=ch;                 //让b中的c成员去ch的值
	printf("整数%d的二进制为:",ch);           //输出ch的值
    printf("%d",b.bit.b0);           //输出位域中的第一个二进制位
	printf("%d",b.bit.b1);           //输出位域中的第二个二进制位
	printf("%d",b.bit.b2);
	printf("%d",b.bit.b3);
	printf("%d",b.bit.b4);
	printf("%d",b.bit.b5);
	printf("%d",b.bit.b6);
	printf("%d",b.bit.b7);
	return 0;
}