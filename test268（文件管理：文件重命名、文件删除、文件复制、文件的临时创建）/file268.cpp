#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

#define N 30

/*
//文件重命名
int main()
{
    char oldname[]="file.txt";
    char newname[]="file1.txt";
    if(rename(oldname,newname)==0)
        cout<<"文件重命名成功!\n";
    else
    {
        cout<<"不能将文件"<<oldname<<"改为"<<newname<<endl;
        exit(0);
    }
    return 0;
}
*/


/*
//文件的删除
int main()
{
    char remoname[]="file3.txt";
    if(remove(remoname)==0)
        cout<<"删除文件"<<remoname<<"成功\n";
    else
    {
         cout<<"删除文件失败\n\n";
         exit(1);
    }
    return 0;
}
*/

/*
//文件的复制1
int main()
{
    char c;
    FILE *fp1,*fp2;
    if((fp1=fopen("file4.txt","rt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    if((fp2=fopen("file5.txt","wt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }

    while((c=fgetc(fp1))!=EOF)
    {
        fputc(c,fp2);
    }
    /*或
    while(!feof(fp1))
    {
        c=fgetc(fp1);
        fputc(c,fp2);
    }


    fclose(fp1);
    fclose(fp2);
    return 0;
}
*/


/*
//文件复制2
int main()
{
    char c[N];
    FILE *fp1,*fp2;
    if((fp1=fopen("file6.txt","rt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }
    if((fp2=fopen("file7.txt","wt+"))==NULL)
    {
        cout<<"打开文件失败!\n";
        exit(1);
    }

    if(fgets(c,N,fp1)!=NULL);
      fputs(c,fp2);

    fclose(fp1);
    fclose(fp2);
    return 0;
}
*/


//文件的临时创建
int main()
{
    FILE *fp;
    char *tmpfile,str[N];
    tmpfile=tmpnam(NULL);
    if((fp=fopen("file8.txt","wt+"))==NULL)
    {
        cout<<"文件打开失败!\n";
        exit(1);
    }

    cout<<"临时文件名:"<<tmpfile<<endl;
    cout<<"请输入字符串:";
    cin>>str;
    fputs(str,fp);

    fclose(fp);
    return 0;
}
