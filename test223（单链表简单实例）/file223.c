#include <stdio.h>
struct st
{
	char name[10];
	int n;
	float score;
	struct st *next;            //定义结构类型指针next
};
void main()
{
	struct st s1={"Wanghu",5324,98.5,NULL};            //定义结构变量s1并进行初始化
	struct st s2={"Liuli",32121,78.5,NULL};
	struct st s3={"Huatao",45221,86.0,NULL};
	struct st s4={"Yuyan",21243,89.0,NULL};
	struct st *head;                                               //定义结构体头指针head
	head=&s1;                                                      //使head指向结构体s1
	s1.next=&s2;                                                  //使s1中的next指针指向结构体s2
	s2.next=&s3;
	s3.next=&s4;
	s4.next=NULL;                                           //是s4中的next为空
	struct st *p=head;                             //定义结构体指针指向链表的头结点
	while(p!=NULL)                               //通过while循环输出所有节点
	{
	   printf("%s,%d,%.lf\n",p->name,p->n,p->score);
	   p=p->next;
	}
}