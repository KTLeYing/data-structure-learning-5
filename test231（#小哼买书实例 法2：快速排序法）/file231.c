#include <stdio.h>
int a[1000],n;
void quicksorted(int left,int right)
{
    int i,j,t,temp;
	if(left>right)
		return ;
	temp=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
     	while(i<j && a[j]>=temp)
	    	j--;
    	while(i<j && a[i]<=temp)
		    i++;
	    if(i<j)
		{
	       t=a[i];
	       a[i]=a[j];
	       a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;
	quicksorted(left,i-1);
	quicksorted(i+1,right);
	return ;
}
int main()
{
   int i;
   printf("pleaes input all the number:");
   scanf("%d",&n);
   printf("plesae input all the numbers:");
   for(i=0;i<=n;i++)
	   scanf("%d",&a[i]);
   quicksorted(0,n);
   printf("the final sorted is:%d ",a[0]);
   for(i=1;i<=n;i++)
   {
	   if(a[i]!=a[i-1])
	   printf("%d ",a[i]);
   }
   return 0;
}