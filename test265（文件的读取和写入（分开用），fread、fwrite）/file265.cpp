#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#define N 1000

using namespace std;

/*
//文件的写入
int main()
{
    FILE *fp;
    char array[N];
    int i,len;
    if((fp=fopen("file.txt","wt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }

    cout<<"请输入数据:";
       cin>>array;
    len=strlen(array);
    for(i=0;i<len;i++)
       fwrite(&array[i],sizeof(char),1,fp);

    fclose(fp);
    return 0;
}
*/

//文件的读取
int main()
{
    FILE *fp;
    if((fp=fopen("file1.txt","rt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    char array[N];
    int i=0,len;
    while(!feof(fp))
    {
        fread(&array[i],sizeof(char),1,fp);
        i++;
    }
    len=strlen(array);
    for(i=0;i<len;i++)
        cout<<array[i]<<" ";
    return 0;
}


