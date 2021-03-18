#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

struct Book
{
   string id;
   string name;
   double price;
};
typedef struct LNode
{
	Book data;
	struct LNode *next;
}LNode,*LinkList;

string head_1,head_2,head_3;
int length;

Status InitList_L(LinkList &L)
{
   L=new LNode;
   L->next=NULL;
   return OK;
}

Status GetElem_L(LinkList L,int i,Book &e)
{
    int j;
	LinkList p;
	p=L->next;
	j=1;
	while(j<i && p)
	{
		p=p->next;
	    ++j;
    }
	if(!p || j>i)
	   return ERROR;
	e=p->data;
	return OK;
}

LNode *LocateElem_L(LinkList L,int e)
{
    LinkList p;
	p=L->next;
	while(p && p->data.price!=e)
		p=p->next;
	return p;
}

Status ListInsert_L(LinkList &L,int i,Book &e)
{
    int j;
	LinkList p,s;
	p=L;
	j=0;
	while(p && j<i-1)
	{
	   p=p->next;
	   ++j;
	}
    if(!p || j>i-1)
      return ERROR;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	++length;
	return OK;
}

Status ListDelete_L(LinkList &L,int i)
{
    LinkList p,q;
	int j;
	p=L;
	j=0;
	while((p->next) && (j<i-1))
	{
	    p=p->next;
		++j;
	}
	if(!(p->next) || (j>i-1))
		return ERROR;
    q=p->next;
	p->next=q->next;
	delete q;
	--length;
	return OK;
}

void CreateList_H(LinkList &L,int n)
{
    LinkList p;
    L=new LNode;
    L->next=NULL;
    length=0;
    fstream file;
    file.open("book.txt");
    if(!file)
    {
       cout<<"未能找到相关文件，无法打开！"<<endl;
	   exit(ERROR); 
	}
	file>>head_1>>head_2>>head_3;
	while(!file.eof())
	{
	   p=new LNode;
	   file>>p->data.id>>p->data.name>>p->data.price;
	   p->next=L->next;
	   L->next=p;
	   length++;
	}
	file.close();
}

void CreateList_R(LinkList &L,int n)
{
    LinkList p,r;
    L=new LNode;
    L->next=NULL;
	r=L;
    length=0;
    fstream file;
    file.open("book.txt");
    if(!file)
    {
       cout<<"未能找到相关文件，无法打开！"<<endl;
	   exit(ERROR); 
	}
	file>>head_1>>head_2>>head_3;
	while(!file.eof())
	{
	   p=new LNode;
	   file>>p->data.id>>p->data.name>>p->data.price;
	   p->next=NULL;
	   r->next=p;
	   r=p;
	   length++;
	}
	file.close();
}



int main()
{
   int a,n,choose;
   double price;
   Book e;
   LinkList L,p;
   cout<<"1.建立\n";
   cout<<"2.输入\n";
   cout<<"3.取值\n";
   cout<<"4.查找\n";
   cout<<"5.插入\n";
   cout<<"6.删除\n";
   cout<<"7.输出\n";
   cout<<"8.退出\n\n";

   choose=-1;
   while(choose!=0)
   {
	   cout<<"请选择:";
       cin>>choose;
	   switch(choose)
	   {
	      case 1:
			  if(InitList_L(L))
				  cout<<"成功建立链表\n\n";
			  break;
		  case 2:
			  CreateList_R(L,length);
			  cout<<"输入book.txt信息完毕\n\n";
			  break;
		  case 3:
			  cout<<"请输入一个位置用于取值:";
			  cin>>a;
			  if(GetElem_L(L,a,e))
			  {
			      cout<<"查找成功\n";
				  cout<<"第"<<a<<"本图书的信息是:\n";
				  cout<<left<<setw(15)<<e.id<<"\t"<<left<<setw(50)
                         <<e.name<<"\t"<<left<<setw(5)<<e.price<<endl<<endl;
			  }
			  else
				  cout<<"查找失败\n\n";
			  break;
		  case 4:
			  cout<<"请输入要查找的价格:";
			  cin>>price;
			  if(LocateElem_L(L,price)!=NULL)
			  {
				  cout<<"查找成功\n";
				  cout<<"该价格对应的书名为:"<<LocateElem_L(L,price)->data.name<<endl<<endl;
			  }
			  else
				  cout<<"查找失败!定价"<<price<<"没有找到\n\n";
			  break;
		  case 5:
			  cout<<"请输入插入的位置和书的信息，包括：编号 书名 价格（用空格隔开）:";
			  cin>>a;
			  cin>>e.id>>e.name>>e.price;
			  if(ListInsert_L(L,a,e))
				  cout<<"插入成功\n\n";
			  else
			     cout<<"插入失败!\n\n";
			  break;
		  case 6:
			  cout<<"请输入所要删除的书籍位置:";
			  cin>>a;
			  if(ListDelete_L(L,a))
				  cout<<"删除成功!\n\n";
			  else
				  cout<<"删除失败!\n\n";
			  break;
		  case 7:
			  cout<<"当前图书系统信息系统（链表）读出:\n";
			  p=L->next;
              while(p)
			  {
			     cout<<left<<setw(15)<<p->data.id<<"\t"<<left<<setw(50)<<p->data.name
					 <<"\t"<<left<<setw(5)<<p->data.price<<endl;
				 p=p->next;
			  }
			  cout<<endl;
			  break;
	  }
   }
   return 0;
}

