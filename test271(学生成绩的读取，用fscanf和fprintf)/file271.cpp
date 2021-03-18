#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

int FileRead(char (*p)[10])      //文件读取信息处理
{
    FILE *fp1,*fp2,*fp3;
    int score[10][4];
    float aver[10];
    char xuehao[10][10],name[10][20];
    char t[5];
    int i,j,k=0;
    float a[10],*p1;
    p1=a;
    if((fp1=fopen("file.txt","r+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    for(i=0;i<10;i++)
    {
        fscanf(fp1,"%s",xuehao[i]);
        fscanf(fp1,"%s",name[i]);
        for(i=0;i<4;i++)
           fscanf(fp1,"%f",score[i][j]);
        *(p1+i)=(score[i][0]+score[i][1]+score[i][2]+score[i][3])/4.0;
    }
    fclose(fp1);
    if((fp2=fopen("file1.txt","w+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    for(i=0;i<10;i++)
    {
        fprintf(fp2,"%10s",xuehao[i]);
        fprintf(fp2,"%10s",name[i]);
        for(i=0;i<4;i++)
           fprintf(fp2,"%3d",score[i][j]);
        fprintf(fp2,".1f%f",*(p1+i));
    }
    fclose(fp2);
    if((fp3=fopen("file2.txt","r+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    for(i=0;i<10;i++)
    {
        fscanf(fp3,"%s",xuehao[i]);
        fscanf(fp3,"%s",name[i]);
        for(i=0;i<4;i++)
           fscanf(fp3,"%d",score[i][j]);
        fscanf(fp3,"%f",a[i]);
    }
    for(i=0;i<10;i++)
       cout<<xuehao[i]<<"\t"<<name[i]<<"\t"<<score[i][0]<<"\t"<<score[i][1]<<"\t"<<score[i][2]<<"\t"<<score[i][3]<<"\t"<<a[i]<<"\n";
    fclose(fp3);
    return 0;
}


int main()
{
    char s[][10]={"学号","姓名","语文","数学","英语","计算机","平均成绩"};
    FileRead(s);
    return 0;
}
