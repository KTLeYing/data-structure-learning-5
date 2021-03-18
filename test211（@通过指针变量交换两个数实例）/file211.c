//法1：
#include<stdio.h>
void change(int *s1,int *s2);
int main()
{
    int x,y,*p1,*p2;  //定义指针变量
	printf("please input x and y:");
	scanf("%d%d",&x,&y);
	p1=&x;     //指针变量初始化，通过指针传递数据
	p2=&y;
	printf("before change:x is %d;y is %d\n",x,y);
	change(p1,p2);    //调用函数（用指针变量名）
	printf("after change:x is %d;y is %d\n",x,y);
	return 0;
}
void change(int *s1,int *s2)   //通过指针传递数据 
{
    int t;
	t=*s1;
	*s1=*s2;
    *s2=t;
}



/*//法2：
#include<stdio.h>
void change(int *s1,int *s2);
int main()
{
    int x,y;  //定义指针变量
	printf("please input x and y:");
	scanf("%d%d",&x,&y);
	printf("before change:x is %d;y is %d\n",x,y);
	change(&x,&y);    //调用函数且间接指针赋值，即*s1=&x,*s2=&y
	printf("after change:x is %d;y is %d\n",x,y);
	return 0;
}
void change(int *s1,int *s2)   //通过指针传递数据 
{
    int t;
	t=*s1;
	*s1=*s2;
    *s2=t;
}*/