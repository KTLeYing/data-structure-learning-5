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
         cout<<"打开文件失败!\n";
         exit(1);
     }

     while(1)
     {
         cout<<"请输入序号:";
         cin>>i;
         if(i<1 || i>N)
         {
             cout<<"输入序号有错!\n";
             break;
         }
         pos=(i-1)*sizeof(struct student);
         fseek(fp,pos,SEEK_SET);
         fread(&stu,sizeof(struct student),1,fp);
         sum=stu.chinese+stu.math+stu.english;
         cout<<"学号\t\t姓名\t\t语文\t\t数学\t\t英语\t\t总分\t\t平均分\n";
         cout<<stu.no<<"\t"<<stu.name<"\t";      //不同数据类型，cout输出时要分开，不在同一个cout输出(此处特殊，与平时不同)
         cout<<stu.chinese<<"\t"<<stu.math<<"\t"<<stu.english<<"\t"<<sum<<"\t"<<(double)sum/3.0<<endl<<endl;
     }

     fclose(fp);
     return 0;
}
