#include <stdio.h>
int main()
{
    char a[100],s[100];
    int len=0,next,mid,i,count=0;
	printf("请输入字符串:");
    for(i=0;i<100;i++)
	{
	  scanf("%c",&a[i]);
	  if(a[i]=='\0')
		  break;
	  count++;
	}
	len=count;
	mid=len/2;
	for(i=0;i<=mid;i++)   //入栈
	{
	   s[i]=a[i];
	}   
	if(len%2!=0)
		next=mid;
	else
		next=mid+1;
	while(next<len)
	{
	   if(s[mid]==a[next])//匹配
	   {
	      mid++;
		  next++;
	   }
	   else
	     break;
	}
	if(mid==0)
	  printf("该字符串是回文");
	else
	  printf("该字符串不是回文");
	return 0;
}