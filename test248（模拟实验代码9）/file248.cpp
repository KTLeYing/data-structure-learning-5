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
	 cout<<"1.初始化\n";
	 cout<<"2.压栈\n";
	 cout<<"3.弹栈\n";
	 cout<<"0.退出\n\n";
     
	 choose=-1;
	 while(choose!=0)
	 {
		 cout<<"请选择:";
		 cin>>choose;
		 switch(choose)
		 {
		     case 1:
			   if(InitStack(s))
			   {
				  flag=1;
				  cout<<"成功对栈初始化\n\n";
			   }
			   else
				  cout<<"初始化栈失败\n\n";
			   break;
			 case 2:
			 {
				 fstream file;
				 file.open("SqStack.txt");
				 if(!file)
				 {
					 cout<<"错误！不存在此文件！\n\n";
					 exit(ERROR);
				 }
				 if(flag)
				 {
				     flag=1;
                     cout<<"进栈元素依次为:\n";
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
					 cout<<"栈未建立，请重新选择\n\n";
                 file.close();
			 }
				 break;
			 case 3:
				 if(flag!=-1 && flag!=0)
					 cout<<"栈顶元素为:\n"<<GetTop(s)<<endl<<endl;
                 else
					 cout<<"栈中无元素，请重新选择\n"<<endl;
				 break;
			 case 4:
				 cout<<"依次弹出的栈顶元素为:\n";
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