#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H "--------------"

typedef struct person    //定义结构变量，并定义为PERSON
{
	char name[10];       //包含一个字符数组成员，用于保存姓名
	char addr[20];        //包含一个字符数组成员，用于保存地址
	char tele[10];
	char qq[10];
	struct person *next;   //包含一个指针成员，用于连接节点
}PERSON;

PERSON *head;      //定义一个全局变量PERSON指针变量head,用于作为链表的头指针

void lcreate()
{
    PERSON *pb;       //定义一个PERSON型的指针
	char ch;
	do
	{
	   pb=(PERSON *) malc(sizeof(PERSON));     //为节点分配空间，将分配内存的指针保存到变量pb中
	   if(!pb)                     //若pb为空，则内存分配失败，退出程序
	   {
	      printf("内存分配失败");
		  exit(1);
	   }
	   printf("%s\n",H);         
	   printf("姓名:");
	   gets(pb->name);                 //接受用户输入数据，通过指针保存到节点中
	   printf("地址");
	   gets(pb->addr);                 //接受用户输入数据，通过指针保存到节点中
	   printf("电话");
	   gets(pb->tele);
	   printf("QQ");
	   gets(pb->qq);
	   linsert(pb);                //插入节点
	   printf("\n继续输入下一人的信息(y/n)?");
	   ch=getchar();
	   fflush(stdin);
	}while(ch=='y' || ch=='Y');                  //条件判断是否继续输入
}