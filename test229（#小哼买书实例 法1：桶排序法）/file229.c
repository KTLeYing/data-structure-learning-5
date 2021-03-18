#include <stdio.h>
int main()
{
    int a[1000],n,i,t;
	for(i=0;i<=1000;i++)
		a[i]=0;
	printf("please input the all number:");
	scanf("%d",&n);
	printf("please input the numbers:");
	for(i=0;i<=n;i++)      //循环输入图书的ISBN号
	{  
	   scanf("%d",&t);
       a[t]=1;      // 避免重复，标记出现过的ISBN号
	}
	printf("the sorted is:");      // 依次判断1~1000的桶
	for(i=0;i<=1000;i++)
		if(a[i]==1)           //打印出现过的ISBN号
		   printf("%d ",i);
	return 0;
}