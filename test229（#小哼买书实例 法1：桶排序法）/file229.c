#include <stdio.h>
int main()
{
    int a[1000],n,i,t;
	for(i=0;i<=1000;i++)
		a[i]=0;
	printf("please input the all number:");
	scanf("%d",&n);
	printf("please input the numbers:");
	for(i=0;i<=n;i++)      //ѭ������ͼ���ISBN��
	{  
	   scanf("%d",&t);
       a[t]=1;      // �����ظ�����ǳ��ֹ���ISBN��
	}
	printf("the sorted is:");      // �����ж�1~1000��Ͱ
	for(i=0;i<=1000;i++)
		if(a[i]==1)           //��ӡ���ֹ���ISBN��
		   printf("%d ",i);
	return 0;
}