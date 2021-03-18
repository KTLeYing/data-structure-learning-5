#include<stdio.h>
int main()
{
    int i,j,k,a[11];
	for(i=0;i<=10;i++)
		a[i]=0;
	for(i=1;i<=5;i++)
	{
	   scanf("%d",&k);
	   a[k]++;
	}
	printf("the sorted number from max to min is:");
	for(i=10;i>=0;i--)
		for(j=1;j<=a[i];j++)
			printf("%d ",i);
    return 0;
} 