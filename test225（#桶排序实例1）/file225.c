#include <stdio.h>
int main()
{
    int a[11],i,j,t;
	for(i=0;i<=10;i++)          //��ʼ��0~10�ֵĴ���Ϊ0;i�������
		a[i]=0;
	printf("please input the numbes:");
	for(i=1;i<=5;i++)
	{
	   scanf("%d",&t);
	   a[t]++;           //����t�������������
	}
    printf("the sorted number from min to max is:");
	for(i=0;i<=10;i++)           //������ּ��ξʹ�ӡ����
	  for(j=1;j<=a[i];j++)
		  printf("%d ",i);
	  return 0;
}