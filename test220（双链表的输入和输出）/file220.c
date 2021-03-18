#include <stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
	struct node *pre;
	struct node *next;
}headnode,*link;
void creat(link *head)
{
   int i,n;
   link p,q;
   (*head)=(link)malloc(sizeof(headnode));
   (*head)->pre=*head;
   (*head)->next=NULL;
   q=*head;
   printf("输入链表的大小:");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
      p=(link)malloc(sizeof(headnode));
	  printf("输入数据:");
	  scanf("%d",&p->data);
	  p->next=NULL;
	  p->pre=q;
	  q->next=p;
	  q=p;
   }
}
void prin(link head)
{
    head=head->next;
	while(head)
    {
	   printf("%d  ",head->data);
	   head=head->next;
	}
}
void main()
{
     link L;
	 creat(&L);
	 prin(L);
}
