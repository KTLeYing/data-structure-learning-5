#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

#define N 30

//�ļ�������
int ReFileName()
{
    char oldname[]="file.txt";
    char newname[]="file1.txt";
    if(rename(oldname,newname)==0)
        cout<<"�ļ��������ɹ�!\n";
    else
    {
        cout<<"���ܽ��ļ�"<<oldname<<"��Ϊ"<<newname<<endl;
    }
}




//�ļ���ɾ��
int FileDelete()
{
    char remoname[]="file3.txt";
    if(remove(remoname)==0)
        cout<<"ɾ���ļ�"<<remoname<<"�ɹ�\n";
    else
    {
         cout<<"ɾ���ļ�ʧ��\n\n";
    }
}


/*
//�ļ��ĸ���1
int main()
{
    char c;
    FILE *fp1,*fp2;
    if((fp1=fopen("file4.txt","rt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }
    if((fp2=fopen("file5.txt","wt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }

    while((c=fgetc(fp1))!=EOF)
    {
        fputc(c,fp2);
    }
    /*��
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



//�ļ�����2
int FileCopy()
{
    char c[N];
    FILE *fp1,*fp2;
    if((fp1=fopen("file6.txt","rt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }
    if((fp2=fopen("file7.txt","wt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }

    if(fgets(c,N,fp1)!=NULL);
    {
        fputs(c,fp2);
        cout<<"�ļ����Ƴɹ�!\n";
    }

    fclose(fp1);
    fclose(fp2);
}



//�ļ�����ʱ����
int FileTempCreate()
{
    FILE *fp;
    char *tmpfile,str[N];
    tmpfile=tmpnam(NULL);
    if((fp=fopen("file8.txt","wt+"))==NULL)
    {
        cout<<"�ļ���ʧ��!\n";
        exit(1);
    }

    cout<<"��ʱ�ļ���:"<<tmpfile<<endl;
    cout<<"�������ַ���:";
    cin>>str;
    fputs(str,fp);
    cout<<"��ʱ�ļ������ɹ�!\n";

    fclose(fp);
}


int main()
{
   int choose=1;
   cout<<"\n\t***********************�ļ������ӱ�********************\n";
   cout<<"\t*\t\t\t1.�ļ�������\t\t\t" "" "" "" "" "" "" "" "*\n";
   cout<<"\t*\t\t\t2.ɾ���ļ�\t\t\t*\n";
   cout<<"\t*\t\t\t3.�����ļ�\t\t\t*\n";
   cout<<"\t*\t\t\t4.������ʱ�ļ�\t\t\t*\n";
   cout<<"\t*\t\t\t0.�˳�\t\t\t\t*\n";
   cout<<"\t*********************************************************\n\n";

   while(choose)
   {
       cout<<"\n��ѡ��:";
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
              cout<<"��������!������ѡ��!\n";
       }
   }
   return 0;
}
