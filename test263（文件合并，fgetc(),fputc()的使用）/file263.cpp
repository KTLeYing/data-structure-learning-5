#include<stdio.h>
#include<fstream>
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    FILE *fp,*fp1,*fp2;
    char ch;
    if((fp=fopen("file.txt","wt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        cout<<"��������ȷ���ļ�·��!\n";
        exit(1);
    }
    if((fp1=fopen("file1.txt","rt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        cout<<"��������ȷ���ļ�·��!\n";
        exit(1);
    }
   if((fp2=fopen("file2.txt","rt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        cout<<"��������ȷ���ļ�·��!\n";
        exit(1);
    }

    while((ch=fgetc(fp1))!=EOF)
    {
        putchar(ch);
        fputc(ch,fp);

    }
    while((ch=fgetc(fp2))!=EOF)
    {
        putchar(ch);
        fputc(ch,fp);
    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
