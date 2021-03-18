#include <stdio.h>
int main()
{
    int a[11],i,j,t;
	for(i=0;i<=10;i++)          //初始化0~10分的次数为0;i代表分数
		a[i]=0;
	printf("please input the numbes:");
	for(i=1;i<=5;i++)
	{
	   scanf("%d",&t);
	   a[t]++;           //计算t分数的输入次数
	}
    printf("the sorted number from min to max is:");
	for(i=0;i<=10;i++)           //输入出现几次就打印几次
	  for(j=1;j<=a[i];j++)
		  printf("%d ",i);
	  return 0;
}