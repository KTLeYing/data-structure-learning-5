#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define H "--------------"

typedef struct person    //����ṹ������������ΪPERSON
{
	char name[10];       //����һ���ַ������Ա�����ڱ�������
	char addr[20];        //����һ���ַ������Ա�����ڱ����ַ
	char tele[10];
	char qq[10];
	struct person *next;   //����һ��ָ���Ա���������ӽڵ�
}PERSON;

PERSON *head;      //����һ��ȫ�ֱ���PERSONָ�����head,������Ϊ�����ͷָ��

void lcreate()
{
    PERSON *pb;       //����һ��PERSON�͵�ָ��
	char ch;
	do
	{
	   pb=(PERSON *) malc(sizeof(PERSON));     //Ϊ�ڵ����ռ䣬�������ڴ��ָ�뱣�浽����pb��
	   if(!pb)                     //��pbΪ�գ����ڴ����ʧ�ܣ��˳�����
	   {
	      printf("�ڴ����ʧ��");
		  exit(1);
	   }
	   printf("%s\n",H);         
	   printf("����:");
	   gets(pb->name);                 //�����û��������ݣ�ͨ��ָ�뱣�浽�ڵ���
	   printf("��ַ");
	   gets(pb->addr);                 //�����û��������ݣ�ͨ��ָ�뱣�浽�ڵ���
	   printf("�绰");
	   gets(pb->tele);
	   printf("QQ");
	   gets(pb->qq);
	   linsert(pb);                //����ڵ�
	   printf("\n����������һ�˵���Ϣ(y/n)?");
	   ch=getchar();
	   fflush(stdin);
	}while(ch=='y' || ch=='Y');                  //�����ж��Ƿ��������
}