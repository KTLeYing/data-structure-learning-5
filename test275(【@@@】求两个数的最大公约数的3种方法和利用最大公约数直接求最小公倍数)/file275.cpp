#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
/*
//��1:շת�����
int main()
{
    int m,n,temp,z,m1,n1;  //������������
    cout<<"��������������(�ÿո����):"<<endl;
    while(cin>>m>>n)
    {
        m1=m;
        n1=n;
        if(m!=0&&n!=0)  //�ж��������Ƿ�����ֵ
        {
            do
            {
                temp=m%n;
                m=n;
                n=temp;
            }
            while(temp);
             cout<<"���Լ��Ϊ��"<<m<<endl;
             z=(m1*n1)/m;
             cout<<"��С������Ϊ:"<<z<<endl<<endl;
        }
        else
            cout<<"������������������"<<endl;  //�޷���Լ���򷵻�
    }
}
*/
//��
/*
int main()
{
    int a,b,a1,b1,z,temp;  //������������
    cout<<"��������������(�ÿո����):"<<endl;
    while(cin>>a>>b)
    {
        a1=a;
        b1=b;
        if(a<b)
        {
          //������������ʹ��������a��
           temp=a;
           a=b;
           b=temp;
        }
        while(b!=0)
        {
           //����շ������ֱ��bΪ0Ϊֹ
          temp=a%b;
          a=b;
          b=temp;
        }
       cout<<"���Լ��Ϊ��"<<a<<endl;
       z=(a1*b1)/a;
       cout<<"��С������Ϊ:"<<z<<endl<<endl;
    }
}
*/
//��
int GCD(int n,int m)//���Լ��
{
    int t;
    if(n<m)
    {
      t=n;
      n=m;
      m=t;
    }
    if(n%m==0)
      return m;
    return GCD(m,n%m);
}

int LCM(int n,int m)//��С������
{
    int z;
    z=n*m/GCD(n,m);
    return z;
}

int main()
{
    int m,n,x,y;
    cout<<"������������:";
    cin>>n>>m;
    x=GCD(n,m);
    y=LCM(n,m);
    cout<<"�������Ϊ:"<<x<<endl;
    cout<<"��С������Ϊ:"<<y<<endl;
}


/*
//��2:��ٷ�����forѭ����
int main()
{
    int j=0;  //����һ�����
    int a,b,z;  //������������
    cout<<"��������������:"<<endl;
    while(cin>>a>>b)
    {
        if(a == 0 || b == 0)
            cout<<"���뺬0���֣�����������"<<endl;
        else
        {
            for(j=a; ;j--)  //����ִ��j
            {
                if(a%j == 0 && b%j == 0)  //��a��b��ͬʱ��j������jΪ���Լ��
                    break;
            }
            cout<<"���Լ��Ϊ:"<<j<<endl;
            z=(a*b)/j;
            cout<<"��С������Ϊ:"<<z<<endl<<endl;
        }
    }
}
*/

/*
//��3:շת�����
int main()
{
    int a,b,a1,b1,z;
    cout<<"����������������:"<<endl;
    while(cin>>a>>b)
    {
        a1=a;
        b1=b;
        if(a == 0 && b == 0)
            cout<<"���뺬0���֣�����������"<<endl;  //����Ƿ����뺬0����
        else
        {
            while(a!=b)
            {
                if(a>b)  //��a����bʱ����a��ȥb
                {
                    a=a-b;
                }
                else
                {
                    b=b-a;  //��b����aʱ����b��ȥa
                }
            }
            cout<<"���Լ��Ϊ:"<<a<<endl;  //ֱ��a=bʱ����ʱ��a����b��Ϊ���Լ��
            z=(a1*b1)/a;
            cout<<"��С������Ϊ:"<<z<<endl<<endl;
        }
    }
}
*/
