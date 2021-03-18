#include <stdio.h>
int main()
{
    struct font
	{
	   unsigned char italic:1;
	   unsigned char bold:1;
	   unsigned char :2;
	   unsigned char underline:2;
	}font1;
	font1.italic=3;     //超出其范围，浪费内存
	//font1.italic=1;
	font1.bold=0;
	font1.underline=6;         //超出其范围，浪费内存
	//font1.underline=2;
	printf("sizeof(font1)=%d\n",sizeof(font1));
	printf("font1.italic=%d\n",font1.italic);
	printf("font1.bold=%d\n",font1.bold);
	printf("font1.underline=%d\n",font1.underline);
	return 0;
}