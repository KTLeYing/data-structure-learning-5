#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
#define N 1000

using namespace std;

/*
//�ļ���д��
int main()
{
    FILE *fp;
    char array[N];
    int i,len;
    if((fp=fopen("file.txt","wt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }

    cout<<"����������:";
       cin>>array;
    len=strlen(array);
    for(i=0;i<len;i++)
       fwrite(&array[i],sizeof(char),1,fp);

    fclose(fp);
    return 0;
}
*/

//�ļ��Ķ�ȡ
int main()
{
    FILE *fp;
    if((fp=fopen("file1.txt","rt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
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


