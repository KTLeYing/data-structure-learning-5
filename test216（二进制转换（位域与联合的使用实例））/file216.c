#include <stdio.h>
struct byte           //����һ��λ��ṹ
{
    unsigned char b0:1;    //��ʾ�����Ƶĵ�һλ
	unsigned char b1:1;    //��ʾ�����Ƶĵڶ�λ
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
};
union bits                 //����һ������
{
	unsigned char c;            //�����޷����ַ��ͱ�����Ա
	struct byte bit;            //����λ��ṹ���Ա
};
int main()
{
	union bits b;          //�������ϱ���b
	int i;               
	unsigned char ch;       //�����޷����ַ��ͱ���ch
	printf("please input the number from 0 to 255:");
	scanf("%d",&ch);               //Ϊch��ֵ
	b.c=ch;                 //��b�е�c��Աȥch��ֵ
	printf("����%d�Ķ�����Ϊ:",ch);           //���ch��ֵ
    printf("%d",b.bit.b0);           //���λ���еĵ�һ��������λ
	printf("%d",b.bit.b1);           //���λ���еĵڶ���������λ
	printf("%d",b.bit.b2);
	printf("%d",b.bit.b3);
	printf("%d",b.bit.b4);
	printf("%d",b.bit.b5);
	printf("%d",b.bit.b6);
	printf("%d",b.bit.b7);
	return 0;
}