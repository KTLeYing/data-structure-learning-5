#include <stdio.h>
struct st
{
	char name[10];
	int n;
	float score;
	struct st *next;            //����ṹ����ָ��next
};
void main()
{
	struct st s1={"Wanghu",5324,98.5,NULL};            //����ṹ����s1�����г�ʼ��
	struct st s2={"Liuli",32121,78.5,NULL};
	struct st s3={"Huatao",45221,86.0,NULL};
	struct st s4={"Yuyan",21243,89.0,NULL};
	struct st *head;                                               //����ṹ��ͷָ��head
	head=&s1;                                                      //ʹheadָ��ṹ��s1
	s1.next=&s2;                                                  //ʹs1�е�nextָ��ָ��ṹ��s2
	s2.next=&s3;
	s3.next=&s4;
	s4.next=NULL;                                           //��s4�е�nextΪ��
	struct st *p=head;                             //����ṹ��ָ��ָ�������ͷ���
	while(p!=NULL)                               //ͨ��whileѭ��������нڵ�
	{
	   printf("%s,%d,%.lf\n",p->name,p->n,p->score);
	   p=p->next;
	}
}