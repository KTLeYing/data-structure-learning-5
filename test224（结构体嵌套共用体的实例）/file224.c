#include <stdio.h>
void main()
{
    struct st                    //����ṹ�����s
	{
	   union                    //������Ƕ�׹��������a       
	   {
	      int m;
		  int n;
	   }a;
	   int x;
	   int y;
	}s;
	s.x=3;                //��3��ֵ��s.x
	s.y=5;
	s.a.m=s.x*s.y;
	s.a.n=s.y-s.x;
	printf("���:%d %d\n",s.a.m,s.a.n);            //���s.a.m��s.a.n�����ڹ���������һ�����ݻḲ�����һ�����ݣ�������������Ľ����Ϊ���һ�����ݵĽ����
}