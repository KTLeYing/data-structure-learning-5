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

//��fprintfд�루�����κ������������ã�
int main()
{
    FILE *fp;
    int i;
    if((fp=fopen("result.txt","wt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }
    fputs("ѧ��\t\t����\t\t����\t��ѧ\tӢ��\n",fp);
    for(i=0;i<N;i++)
    {
        cout<<"����"<<i+1<<"��ͬѧ����Ϣ!\n";
        cout<<"����ѧ��:";
        cin>>stu[i].no;
        cout<<"��������:";
        cin>>stu[i].name;
        cout<<"�������ĳɼ�:";
        cin>>stu[i].chinese;
        cout<<"������ѧ�ɼ�:";
        cin>>stu[i].math;
        cout<<"����Ӣ��ɼ�:";
        cin>>stu[i].english;
        fprintf(fp,"%s\t\t%s\t%d\t%d\t%d\n",stu[i].no,stu[i].name,stu[i].chinese,stu[i].math,stu[i].english);
        cout<<endl;
    }
    fclose(fp);
    return 0;
}

/*
//����fwriteд��(һ�����ַ���������)
int main()
{
    FILE *fp;
    int i;
    if((fp=fopen("result.txt","wt+"))==NULL)
    {
        cout<<"���ļ�ʧ��!\n";
        exit(1);
    }
    fputs("ѧ��\t\t����\t\t����\t��ѧ\tӢ��\n",fp);
    for(i=0;i<N;i++)
    {
        cout<<"����"<<i+1<<"��ͬѧ����Ϣ!\n";
        cout<<"����ѧ��:";
        cin>>stu[i].no;
        cout<<"��������:";
        cin>>stu[i].name;
        cout<<"�������ĳɼ�:";
        cin>>stu[i].chinese;
        cout<<"������ѧ�ɼ�:";
        cin>>stu[i].math;
        cout<<"����Ӣ��ɼ�:";
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
