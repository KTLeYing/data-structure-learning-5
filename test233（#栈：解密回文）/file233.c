#include <stdio.h>
#include <string.h>
int main()
{
    char a[100],s[100];
	int i,len,next,top,mid;
	gets(a);       //����һ���ַ���
	len=strlen(a);      //���ַ�������
	mid=len/2-1;       //���ַ����е�
	top=0;         //ջ�������ĳ�ʼ��
	for(i=0;i<=mid;i++)    //midǰ��Ԫ��һ����ջ
		s[++top]=a[i];
	if(len%2==0)    //�жϳ�����ż���������������ҳ������ַ�ƥ��Ŀ�ʼ�±�
		next=mid+1;
	else
		next=mid+2;
	for(i=next;i<=len-1;i++)      //��ʼƥ��
	{
	    if(a[i]!=s[top])
			break;
		top--;
	}
	if(top==0)      //top=0��˵��ջ�ڵ������ַ�����һһƥ���ˣ���ƥ��ɹ����ǻ����ַ��� 
		printf("Yes\n");
    else
		printf("No\n");
	return 0;
}