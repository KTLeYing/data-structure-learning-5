#include <stdio.h>
int main()
{
    char a[100],s[100];
    int len=0,next,mid,i,count=0;
	printf("�������ַ���:");
    for(i=0;i<100;i++)
	{
	  scanf("%c",&a[i]);
	  if(a[i]=='\0')
		  break;
	  count++;
	}
	len=count;
	mid=len/2;
	for(i=0;i<=mid;i++)   //��ջ
	{
	   s[i]=a[i];
	}   
	if(len%2!=0)
		next=mid;
	else
		next=mid+1;
	while(next<len)
	{
	   if(s[mid]==a[next])//ƥ��
	   {
	      mid++;
		  next++;
	   }
	   else
	     break;
	}
	if(mid==0)
	  printf("���ַ����ǻ���");
	else
	  printf("���ַ������ǻ���");
	return 0;
}