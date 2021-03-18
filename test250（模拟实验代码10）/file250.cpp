#include <iostream>
#include <fstream>
using namespace std;

#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char QElemType;
typedef int Status;

typedef struct
{
    QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue &Q)
{
   Q.base=new QElemType[MAXQSIZE];
   if(!Q.base)
	   exit(OVERFLOW);
   Q.front=Q.rear=0;
   return OK;
}

Status QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
   if((Q.rear+1)%MAXQSIZE==Q.front)
	   return ERROR;
   Q.base[Q.rear]=e;
   Q.rear=(Q.rear+1)%MAXQSIZE;
   return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.rear==Q.front)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	return OK;
}

QElemType GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
		return Q.base[Q.front];
}

int main()
{
   int choose,flag=0;
   SqQueue Q;
   QElemType e,j;
   cout<<"1.��ʼ��\n";
   cout<<"2.���\n";
   cout<<"3.����ͷԪ��\n";
   cout<<"0.�˳�\n\n";

   choose=-1;
   while(choose!=0)
   {
      cout<<"��ѡ��:";
	  cin>>choose;
	  switch(choose)
	  {
	     case 1:
			 if(InitQueue(Q))
			 {
			    flag=1;
				cout<<"���г�ʼ���ɹ�\n\n";
			 }
			 else
				 cout<<"���г�ʼ��ʧ��\n\n";
			 break;
         case 2:
		{
			fstream file;
			file.open("QNode.txt");
			if(!file)
			{
			  cout<<"����δ�ҵ��ļ���\n\n"<<endl;
			  exit(ERROR);
			}
			if(flag)
			{
			   flag=1;
			   cout<<"��ӵ�Ԫ������Ϊ:\n";
			   while(!file.eof())
			   {
			       file>>j;
				   if(file.fail())
					   break;
				   else
				   {
					   EnQueue(Q,j);
				       cout<<j<<" ";
				   }
			   }
			   cout<<endl<<endl;
			}
			else
				cout<<"����δ������������ѡ��\n\n";
			file.close();
		}
		    break;
         case 3:
			 if(flag!=-1 && flag!=0)
				 cout<<"��ͷԪ��Ϊ:\n"<<GetHead(Q)<<endl<<endl;
			 else
                 cout<<"������Ԫ�أ�������ѡ��:\n"<<endl;
			 break;
		 case 4:
			 cout<<"���ε�����ͷԪ��Ϊ:\n";
			 while(DeQueue(Q,e))
			 {
			    
				cout<<e<<" ";
			 }
			 flag=-1;
			 cout<<endl<<endl;
			 break;
	  }
   }
   return 0;
}