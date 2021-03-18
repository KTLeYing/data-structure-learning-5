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
       cout<<"δ���ҵ�����ļ����޷��򿪣�"<<endl;
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
       cout<<"δ���ҵ�����ļ����޷��򿪣�"<<endl;
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
   cout<<"1.����\n";
   cout<<"2.����\n";
   cout<<"3.ȡֵ\n";
   cout<<"4.����\n";
   cout<<"5.����\n";
   cout<<"6.ɾ��\n";
   cout<<"7.���\n";
   cout<<"8.�˳�\n\n";

   choose=-1;
   while(choose!=0)
   {
	   cout<<"��ѡ��:";
       cin>>choose;
	   switch(choose)
	   {
	      case 1:
			  if(InitList_L(L))
				  cout<<"�ɹ���������\n\n";
			  break;
		  case 2:
			  CreateList_R(L,length);
			  cout<<"����book.txt��Ϣ���\n\n";
			  break;
		  case 3:
			  cout<<"������һ��λ������ȡֵ:";
			  cin>>a;
			  if(GetElem_L(L,a,e))
			  {
			      cout<<"���ҳɹ�\n";
				  cout<<"��"<<a<<"��ͼ�����Ϣ��:\n";
				  cout<<left<<setw(15)<<e.id<<"\t"<<left<<setw(50)
                         <<e.name<<"\t"<<left<<setw(5)<<e.price<<endl<<endl;
			  }
			  else
				  cout<<"����ʧ��\n\n";
			  break;
		  case 4:
			  cout<<"������Ҫ���ҵļ۸�:";
			  cin>>price;
			  if(LocateElem_L(L,price)!=NULL)
			  {
				  cout<<"���ҳɹ�\n";
				  cout<<"�ü۸��Ӧ������Ϊ:"<<LocateElem_L(L,price)->data.name<<endl<<endl;
			  }
			  else
				  cout<<"����ʧ��!����"<<price<<"û���ҵ�\n\n";
			  break;
		  case 5:
			  cout<<"����������λ�ú������Ϣ����������� ���� �۸��ÿո������:";
			  cin>>a;
			  cin>>e.id>>e.name>>e.price;
			  if(ListInsert_L(L,a,e))
				  cout<<"����ɹ�\n\n";
			  else
			     cout<<"����ʧ��!\n\n";
			  break;
		  case 6:
			  cout<<"��������Ҫɾ�����鼮λ��:";
			  cin>>a;
			  if(ListDelete_L(L,a))
				  cout<<"ɾ���ɹ�!\n\n";
			  else
				  cout<<"ɾ��ʧ��!\n\n";
			  break;
		  case 7:
			  cout<<"��ǰͼ��ϵͳ��Ϣϵͳ����������:\n";
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

