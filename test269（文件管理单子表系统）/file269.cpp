#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

#define N 30

//文件重命名
int ReFileName()
{
    char oldname[]="file.txt";
    char newname[]="file1.txt";
    if(rename(oldname,newname)==0)
        cout<<"文件重命名成功!\n";
    else
    {
        cout<<"不能将文件"<<oldname<<"改为"<<newname<<endl;
    }
}




//文件的删除
int FileDelete()
{
    char remoname[]="file3.txt";
    if(remove(remoname)==0)
        cout<<"删除文件"<<remoname<<"成功\n";
    else
    {
         cout<<"删除文件失败\n\n";
    }
}


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



//文件复制2
int FileCopy()
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
    {
        fputs(c,fp2);
        cout<<"文件复制成功!\n";
    }

    fclose(fp1);
    fclose(fp2);
}



//文件的临时创建
int FileTempCreate()
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
    cout<<"临时文件创建成功!\n";

    fclose(fp);
}


int main()
{
   int choose=1;
   cout<<"\n\t***********************文件管理单子表********************\n";
   cout<<"\t*\t\t\t1.文件重命名\t\t\t" "" "" "" "" "" "" "" "*\n";
   cout<<"\t*\t\t\t2.删除文件\t\t\t*\n";
   cout<<"\t*\t\t\t3.复制文件\t\t\t*\n";
   cout<<"\t*\t\t\t4.创建临时文件\t\t\t*\n";
   cout<<"\t*\t\t\t0.退出\t\t\t\t*\n";
   cout<<"\t*********************************************************\n\n";

   while(choose)
   {
       cout<<"\n请选择:";
       cin>>choose;
       switch(choose)
       {
           case 1:
              ReFileName();
              break;
           case 2:
              FileDelete();
              break;
           case 3:
              FileCopy();
              break;
           case 4:
              FileTempCreate();
              break;
           case 0:
              return 0;
           default:
              cout<<"输入有误!请重新选择!\n";
       }
   }
   return 0;
}
