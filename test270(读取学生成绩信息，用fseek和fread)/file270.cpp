#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

#define N 5

struct student
{
    char no [9];
    char name[10];
    int chinese,math,english;
}stu;

int main()
{
     FILE *fp;
     int i,sum;
     long pos;
     if((fp=fopen("file.txt","rb+"))==NULL)
     {
         cout<<"���ļ�ʧ��!\n";
         exit(1);
     }

     while(1)
     {
         cout<<"���������:";
         cin>>i;
         if(i<1 || i>N)
         {
             cout<<"��������д�!\n";
             break;
         }
         pos=(i-1)*sizeof(struct student);
         fseek(fp,pos,SEEK_SET);
         fread(&stu,sizeof(struct student),1,fp);
         sum=stu.chinese+stu.math+stu.english;
         cout<<"ѧ��\t\t����\t\t����\t\t��ѧ\t\tӢ��\t\t�ܷ�\t\tƽ����\n";
         cout<<stu.no<<"\t"<<stu.name<"\t";      //��ͬ�������ͣ�cout���ʱҪ�ֿ�������ͬһ��cout���(�˴����⣬��ƽʱ��ͬ)
         cout<<stu.chinese<<"\t"<<stu.math<<"\t"<<stu.english<<"\t"<<sum<<"\t"<<(double)sum/3.0<<endl<<endl;
     }

     fclose(fp);
     return 0;
}
