#include <stdio.h>
int main()
{
    int a[100],i,j,n,t;
	printf("please input all the number:");           
	scanf("%d",&n);
	printf("lease input the numbers:");
	for(i=1;i<=n;i++)                    //ѭ������n��ͼ��ISBN��
		scanf("%d",&a[i]);
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)     
		{
		   if(a[j]>a[j+1])
		   {
		      t=a[j];
			  a[j]=a[j+1];
			  a[j+1]=t;
		   }
		}
	}
	printf("the sorted is:");
	printf("%d ",a[1]);    //�����һ����
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])       //�����ظ�����һ�γ��������
		   printf("%d ",a[i]);
	}
	return 0;
}
