#include <stdio.h>
int a[1000],n;
void quicksorted(int left,int right)
{  
	int i,j,temp,t;
	if(left>right)    //�жϵݹ��Ƿ��������
	   return ;
    temp=a[left];      //temp�д��׼��
	i=left;
	j=right;
	while(i!=j)
	{
	    while(a[j]>=temp && i<j)     //һ���ȴ���������У�˳�����Ҫ��
               j--;
	    while(a[i]<=temp && i<j)      //�ڴ������ҽ���
			   i++;
	   if(i<j)
	   {                  //��������������
		    t=a[i];
			a[i]=a[j];
			a[j]=t;
	   }
	}
    a[left]=a[i];
    a[i]=temp;         //��׼����λ
    quicksorted(left,i-1);       //�ݹ飬�����������
    quicksorted(i+1,right);       //�ݹ飬���������ұ�
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
	 for(i=0;i<=n;i++)                 //������������
		 printf("%d ",a[i]);
	 return 0;
}
