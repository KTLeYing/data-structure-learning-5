#include <stdio.h>
int main()
{
    int i,j,t,n,a[100];
	printf("the total number is:");
	scanf("%d",&n);
	printf("input all the numbers:");
	for(i=0;i<n;i++)
	     scanf("%d",&a[i]);
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
		{
		   if(a[j]<a[j+1])
		   {
		       t=a[j];
			   a[j]=a[j+1];
			   a[j+1]=t;
		   }
		}
	printf("the sorted number is:");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	return 0;
}