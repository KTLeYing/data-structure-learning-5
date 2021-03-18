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
   cout<<"1.初始化\n";
   cout<<"2.入队\n";
   cout<<"3.读队头元素\n";
   cout<<"0.退出\n\n";

   choose=-1;
   while(choose!=0)
   {
      cout<<"请选择:";
	  cin>>choose;
	  switch(choose)
	  {
	     case 1:
			 if(InitQueue(Q))
			 {
			    flag=1;
				cout<<"队列初始化成功\n\n";
			 }
			 else
				 cout<<"队列初始化失败\n\n";
			 break;
         case 2:
		{
			fstream file;
			file.open("QNode.txt");
			if(!file)
			{
			  cout<<"错误！未找到文件！\n\n"<<endl;
			  exit(ERROR);
			}
			if(flag)
			{
			   flag=1;
			   cout<<"入队的元素依次为:\n";
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
				cout<<"队列未建立，请重新选择\n\n";
			file.close();
		}
		    break;
         case 3:
			 if(flag!=-1 && flag!=0)
				 cout<<"队头元素为:\n"<<GetHead(Q)<<endl<<endl;
			 else
                 cout<<"队中无元素，请重新选择:\n"<<endl;
			 break;
		 case 4:
			 cout<<"依次弹出队头元素为:\n";
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