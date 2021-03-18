#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],s[100];
	int i,len,next,top,mid;
	gets(a);       //输入一段字符串
	len=strlen(a);      //求字符串长度
	mid=len/2-1;       //求字符串中点
	top=0;         //栈顶变量的初始化
	for(i=0;i<=mid;i++)    //mid前的元素一次入栈
		s[++top]=a[i];
	if(len%2==0)    //判断长度是偶数还是奇数，并找出进行字符匹配的开始下标
		next=mid+1;
	else
		next=mid+2;
	for(i=next;i<=len-1;i++)      //开始匹配
	{
	    if(a[i]!=s[top])
			break;
		top--;
	}
	if(top==0)      //top=0，说明栈内的所有字符都被一一匹配了，即匹配成功，是回文字符串 
		printf("Yes\n");
    else
		printf("No\n");
	return 0;
}