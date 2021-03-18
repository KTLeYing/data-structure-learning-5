#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

#define N 2

struct Student
{
    char no[10];
    char name[15];
    int chinese,math,english;
}stu[N];

//用fprintf写入（可与任何数据类型连用）
int main()
{
    FILE *fp;
    int i;
    if((fp=fopen("result.txt","wt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    fputs("学号\t\t姓名\t\t语文\t数学\t英语\n",fp);
    for(i=0;i<N;i++)
    {
        cout<<"输入"<<i+1<<"个同学的信息!\n";
        cout<<"输入学号:";
        cin>>stu[i].no;
        cout<<"输入名字:";
        cin>>stu[i].name;
        cout<<"输入语文成绩:";
        cin>>stu[i].chinese;
        cout<<"输入数学成绩:";
        cin>>stu[i].math;
        cout<<"输入英语成绩:";
        cin>>stu[i].english;
        fprintf(fp,"%s\t\t%s\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english);
        cout<<endl;
    }
    fclose(fp);
    return 0;
}

/*
//或用fwrite写入(一般与字符类型连用)
int main()
{
    FILE *fp;
    int i;
    if((fp=fopen("result.txt","wt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    fputs("学号\t\t姓名\t\t语文\t数学\t英语\n",fp);
    for(i=0;i<N;i++)
    {
        cout<<"输入"<<i+1<<"个同学的信息!\n";
        cout<<"输入学号:";
        cin>>stu[i].no;
        cout<<"输入名字:";
        cin>>stu[i].name;
        cout<<"输入语文成绩:";
        cin>>stu[i].chinese;
        cout<<"输入数学成绩:";
        cin>>stu[i].math;
        cout<<"输入英语成绩:";
        cin>>stu[i].english;
        //fprintf(fp,"%s\t\t%s\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english);
        fwrite(&stu[i].no,sizeof(char),10,fp);
        fputs("\t\t",fp);
        fwrite(&stu[i].name,sizeof(char),11,fp);
        fputs("\t",fp);
        fwrite(&stu[i].chinese,sizeof(char),3,fp);
        fputs("\t",fp);
        fwrite(&stu[i].math,sizeof(char),3,fp);
        fputs("\t",fp);
        fwrite(&stu[i].english,sizeof(char),3,fp);
        fputs("\n",fp);
        cout<<endl;
    }
    fclose(fp);
    return 0;
}
*/
