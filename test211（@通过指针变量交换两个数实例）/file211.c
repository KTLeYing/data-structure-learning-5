//��1��
#include<stdio.h>
void change(int *s1,int *s2);
int main()
{
    int x,y,*p1,*p2;  //����ָ�����
	printf("please input x and y:");
	scanf("%d%d",&x,&y);
	p1=&x;     //ָ�������ʼ����ͨ��ָ�봫������
	p2=&y;
	printf("before change:x is %d;y is %d\n",x,y);
	change(p1,p2);    //���ú�������ָ���������
	printf("after change:x is %d;y is %d\n",x,y);
	return 0;
}
void change(int *s1,int *s2)   //ͨ��ָ�봫������ 
{
    int t;
	t=*s1;
	*s1=*s2;
    *s2=t;
}



/*//��2��
#include<stdio.h>
void change(int *s1,int *s2);
int main()
{
    int x,y;  //����ָ�����
	printf("please input x and y:");
	scanf("%d%d",&x,&y);
	printf("before change:x is %d;y is %d\n",x,y);
	change(&x,&y);    //���ú����Ҽ��ָ�븳ֵ����*s1=&x,*s2=&y
	printf("after change:x is %d;y is %d\n",x,y);
	return 0;
}
void change(int *s1,int *s2)   //ͨ��ָ�봫������ 
{
    int t;
	t=*s1;
	*s1=*s2;
    *s2=t;
}*/