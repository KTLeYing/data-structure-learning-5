#include <stdio.h>
struct queue      //������еĽṹ��
{
    int data[1000];
	int head;
	int tail;
};
struct stack      //����ջ�Ľṹ��
{
    int data[10];
	int top;
};
int main()
{
    struct queue q1,q2;       //������еĽṹ����
	struct stack s;            //����ջ�Ľṹ����
	int book[10];
	int i,t;
	q1.head=0;         //���г�ʼ��
	q1.tail=0;
	q2.head=0;
	q2.tail=0;
	s.top=0;           //ջ�ĳ�ʼ��
	for(i=1;i<=9;i++)
		book[i]=0;          //��ʼ��������������ϵ��Ƶ�����
	printf("please input person1 numbers:");
	for(i=0;i<=5;i++)           //����в���6������person1���ϵ���
	{
	    scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	printf("please input person2 numbers:");
	for(i=0;i<=5;i++)          //����в���6������person2���ϵ���
	{
	   scanf("%d",&q2.data[q2.tail]);
	   q2.tail++;
	}
	while(q1.head<q1.tail && q2.head<q2.tail)              //���в�Ϊ��ʱִ��
	{
	   t=q1.data[q1.head];               //person1����
	   if(book[t]==0)                //��������û��t����
	   {                              //person1����û��Ӯ��
	      q1.head++;                //person1�����һ���ƣ���һ���Ƴ���
		  s.top++;
		  s.data[s.top]=t;                    //������Ʒŵ����棬����ջ
		  book[t]=1;                     //���������t����
	   }
	   else
	   {                       //person1���ֿ���Ӯ��
	       q1.head++;            //person1�����һ���ƣ���һ���Ƴ���
		   q1.data[q1.tail]=t;     //�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
		   q1.tail++;
		   while(s.data[s.top]!=t)      //�����Ͽ���Ӯ�������ηŵ������Ƶ�ĩβ
		   {
		      book[s.data[s.top]]=0;        //ȡ�����
			  q1.data[q1.tail]=s.data[s.top];          //���ηŵ���β
			  q1.tail++;
			  s.top--;                 //ջ������һ���ƣ�����ջ��Ҫ��1
		   }
		   book[s.data[s.top]]=0;   //�ջ�����Ϊt���ƣ���ΪӮ�����ǣ�������ͬ���Ƽ����м���ŵ��ƣ��������ȡ����Щ��ͬ���ƺ󣬻�Ҫ����ȡ�����һ����t��ͬ���ƣ�
		   q1.data[q1.tail]=s.data[s.top];     
		   q1.tail++;
		   s.top--;
	   }
	   if(q1.head==q1.tail)      //person1���е����Ѿ����꣬��Ϸ����������ѭ��
		   break;
       t=q2.data[q2.head];     //person2����
	   if(book[t]==0)      //��������û��t����
	   {                    //person2����û��Ӯ��
	      q2.head++;
		  s.top++;
		  s.data[s.top]=t;     //������Ʒŵ����棬����ջ
		  book[t]=1;            //���������t����
	   }
	   else
	   {                      //person2���ֿ���Ӯ��
	       q2.head++;               //person2�����һ���ƣ���һ���Ƴ���
		   q2.data[q2.tail]=t;     //�����ŰѴ�����Ʒŵ������Ƶ�ĩβ
		   q2.tail++;
		   while(s.data[s.top]!=t)          //�����Ͽ���Ӯ�������ηŵ������Ƶ�ĩβ
		   {
		      book[s.data[s.top]]=0;            //ȡ�����
			  q2.data[q2.tail]=s.data[s.top];              //���ηŵ���β
			  q2.tail++;               
			  s.top--;                              //ջ������һ���ƣ�����ջ��Ҫ��1
		   }                     
		   book[s.data[s.top]]=0;  //�ջ�����Ϊt���ƣ���ΪӮ�����ǣ�������ͬ���Ƽ����м���ŵ��ƣ��������ȡ����Щ��ͬ���ƺ󣬻�Ҫ����ȡ�����һ����t��ͬ���ƣ�
		   q2.data[q2.tail]=s.data[s.top];
		   q2.tail++;
		   s.top--;
	   }
	}
	
	if(q2.head==q2.tail)            //������2Ϊ�գ�����person1Ӯ
	{
	    printf("person1 win\n");
		printf("person1 ������:");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0)
		{
		   printf("\n���ϵ�����:");
		   for(i=1;i<=s.top;i++)
			   printf(" %d",s.data[i]);
		}
		else
			printf("\n�����Ѿ�û����");
	}
	else
	{                                //������1Ϊ�գ�����person1Ӯ
	    printf("person2 win\n");
		printf("person2 ������:");
		for(i=q2.head;i<=q2.tail-1;i++)
			printf(" %d",q2.data[i]);
		if(s.top>0)
		{
		   printf("\n���ϵ�����:");
		   for(i=1;i<=s.top;i++)
			   printf(" %d",s.data[i]);
		}
		else
			printf("\n�����Ѿ�û����");
	}
	return 0;
}