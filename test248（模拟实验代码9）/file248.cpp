#include <iostream>
#include <fstream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef char SElemType;

typedef struct
{
   SElemType *base;
   SElemType *top;
   int stacksize;
}SqStack;

Status InitStack(SqStack &S)
{
   S.base=new SElemType[MAXSIZE];
   if(!S.base)
	   exit(OVERFLOW);
   S.top=S.base;
   S.stacksize=MAXSIZE;
   return OK;
}

Status Push(SqStack &S,SElemType e)
{
   if(S.top-S.base==S.stacksize)
	   return ERROR;
   *(S.top++)=e;
   return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
   if(S.top==S.base)
	   return ERROR;
   e=*(--S.top);
   return OK;
}

char GetTop(SqStack S)
{
   if(S.top!=S.base)
	   return *(S.top-1);
}

int main()
{
     SqStack s;
	 int choose,flag=0;
	 SElemType j,e,t;
	 cout<<"1.��ʼ��\n";
	 cout<<"2.ѹջ\n";
	 cout<<"3.��ջ\n";
	 cout<<"0.�˳�\n\n";
     
	 choose=-1;
	 while(choose!=0)
	 {
		 cout<<"��ѡ��:";
		 cin>>choose;
		 switch(choose)
		 {
		     case 1:
			   if(InitStack(s))
			   {
				  flag=1;
				  cout<<"�ɹ���ջ��ʼ��\n\n";
			   }
			   else
				  cout<<"��ʼ��ջʧ��\n\n";
			   break;
			 case 2:
			 {
				 fstream file;
				 file.open("SqStack.txt");
				 if(!file)
				 {
					 cout<<"���󣡲����ڴ��ļ���\n\n";
					 exit(ERROR);
				 }
				 if(flag)
				 {
				     flag=1;
                     cout<<"��ջԪ������Ϊ:\n";
                     while(!file.eof())
					 {
					      file>>j;
						  if(file.fail())
							  break;
						  else
						  {
						      Push(s,j);
							  cout<<j<<" ";
						  }
					 }
					 cout<<endl<<endl;
				 }
				 else
					 cout<<"ջδ������������ѡ��\n\n";
                 file.close();
			 }
				 break;
			 case 3:
				 if(flag!=-1 && flag!=0)
					 cout<<"ջ��Ԫ��Ϊ:\n"<<GetTop(s)<<endl<<endl;
                 else
					 cout<<"ջ����Ԫ�أ�������ѡ��\n"<<endl;
				 break;
			 case 4:
				 cout<<"���ε�����ջ��Ԫ��Ϊ:\n";
				 while(Pop(s,t))
				 {
				     flag=-1;
				      cout<<t<<" ";
				 }
				 cout<<endl<<endl;
				 break;
		 }
	 }
	 return 0;
}