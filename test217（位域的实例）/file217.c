#include <stdio.h>
int main()
{
    struct bs
	{
		unsigned a:1;             //aռ��1��������λ
		unsigned b:3;             //bռ��3��������λ
		unsigned c:4;             //cռ��4��������λ
	}
    bit,*pbit;             //����bs�ͱ���bit��bs��ָ��*pbit
	bit.a=1;          //Ϊλ��ֵ
	bit.b=7;
	bit.c=15;
	printf("%d,%d,%d/n",bit.a,bit.b,bit.c);           //�����͸�ʽ���3��λ�������
	pbit=&bit;           //��λ�����bit�ĵ�ַ����ָ�����pbit
	pbit->a=0;              //��ָ�뷽ʽ��λ��a���¸�ֵ
	pbit->b&=3;     //�൱��pbit->b=pbit->b+3
	pbit->c|=1;       //�൱��pbit->c=pbit->+1
	printf("%d,%d,%d/n",pbit->a,pbit->b,pbit->c);
	return 0;
}