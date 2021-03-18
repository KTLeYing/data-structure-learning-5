#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

#define N 100

int main()
{
    FILE *fp1,*fp2;
    char a[N];
    int i=0;
    if((fp1=fopen("file1.txt","rt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    if((fp2=fopen("file2.txt","wt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }

    while(!feof(fp1))
    {
        fread(&a[i],sizeof(char),1,fp1);
        fprintf(fp2,"%c",a[i]);
        i++;
    }
    return 0;
}
