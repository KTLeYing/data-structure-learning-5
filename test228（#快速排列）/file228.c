#include <stdio.h>
int a[1000],n;
void quicksorted(int left,int right)
{  
	int i,j,temp,t;
	if(left>right)    //判断递归是否继续进行
	   return ;
    temp=a[left];      //temp中存基准数
	i=left;
	j=right;
	while(i!=j)
	{
	    while(a[j]>=temp && i<j)     //一定先从右往左进行（顺序很重要）
               j--;
	    while(a[i]<=temp && i<j)      //在从左往右进行
			   i++;
	   if(i<j)
	   {                  //交换相遇的两数
		    t=a[i];
			a[i]=a[j];
			a[j]=t;
	   }
	}
    a[left]=a[i];
    a[i]=temp;         //基准数归位
    quicksorted(left,i-1);       //递归，继续处理左边
    quicksorted(i+1,right);       //递归，继续处理右边
    return ;
}
int main()
{
	 int i;
	 printf("please input all the number:");  
	 scanf("%d",&n);
	 printf("plesae input the numbers:"); 
	 for(i=0;i<=n;i++)
		 scanf("%d",&a[i]);
	 quicksorted(0,n);
	 printf("the sorted numbers is:");
	 for(i=0;i<=n;i++)                 //输出最后排序结果
		 printf("%d ",a[i]);
	 return 0;
}
