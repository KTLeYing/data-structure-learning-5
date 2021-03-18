#include <stdio.h>
void main()
{
    struct st                    //定义结构体变量s
	{
	   union                    //定义内嵌套共用体变量a       
	   {
	      int m;
		  int n;
	   }a;
	   int x;
	   int y;
	}s;
	s.x=3;                //将3赋值给s.x
	s.y=5;
	s.a.m=s.x*s.y;
	s.a.n=s.y-s.x;
	printf("结果:%d %d\n",s.a.m,s.a.n);            //输出s.a.m和s.a.n（由于共用体的最后一个数据会覆盖最后一个数据，所有两个输出的结果均为最后一个数据的结果）
}