/*
//eg1:��n�Ľ׳�ģ��(n+2)��ֵ
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>

using namespace std;

int a[100005];
int w = 1;//λ����ʼΪ1

string fac(int n)//��׳�
{

    string str;
    for(int z = 1; z <= n; z++)
    {
        int x = 0;
        for(int i = 1; i <= w; ++i)
        {
           a[i] = a[i]*z + x;//�����˺�Ľ��
           x = a[i]/10;//���x=0˵��a[i]<10,���޽�λ����x>0���н�λ
           a[i] = a[i]%10;//��iλ���������������ʵ��ȡ��
        }
        while (x > 0)//�н�λ
        {
           w++;//λ��+1
           a[w] = x%10;//��λ������
           x = x/10;
        }
    }
    for(int j=w;j>=1;--j)
        str+= a[j]+'0';//�������е����ݷŵ�string����
    cout<<str<<endl;
    return str;
}

int mod(string str,int n)//������
{
    int l,y;
    l=str.length();
    y=(str[0]-'0')%n;//ͬ�ඨ��
    for(int i=1;i<l;i++)
    {
       y=(y*10+str[i]-'0')%n;
    }
    return y;
}

int main()
{
    int n;
    while(cin>>n)
    {
       a[1] = 1;
       w = 1;
       cout<<mod(fac(n),(n+2))<<endl<<endl;
    }
}
*/

/*
//eg2:������n�Ľ׳˳���(n-m)�������Ƕ���
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
    string n,m;
    while(cin>>m>>n)
    {
       cout<<"0"<<endl;
    }
}
/*
/*˵����
n! = 1*2*3*...*(n-m-1)*(n-m)*(n-m+1)*...*(n-1)*n
n!%(n-m) = 0
*/

/*
//eg3:һ������n,��n^n(n��n�η�)�����λ����k(������ߵ�һλ)�����k֮������n^n����k��������
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int _pow(int a,long long n,int m)
{// ��a^n%m�õ�������
   if(n==0)
      return 1%m;
   long long t=_pow(a,n/2,m);
   if(n%2==1)
      return(t*t*a)%m;
   else
      return(t*t)%m;
}

int main()
{
   int n,t,i,m,k;
   long long sum;
   double z;
   cin>>t;
   for(i=1;i<=t;i++)
   {
      cin>>n;
      m=log10(pow(n,n))+1;//�ȼ����n^n�ĳ���
      k=pow(n,n)/pow(10,m-1);//��n^n����10��n^nλ����1�η����õ����λ
      cout<<"Case "<<i<<":";
      cout<<k<<" "<<_pow(n, n, k)<<endl<<endl;
   }
}
/*
/*˵����
����1���������n^n�����λ����
�ڴ˴��漰�������⺯��
C �⺯�� double pow(double x, double y) ���� x �� y ���ݣ��� x^y��
C �⺯�� double log10(double x) ���� x �ĳ��ö���������Ϊ 10 �Ķ�������
����pow()���������n^n��������log10�����λ����
����n^n��λ��Ϊm
��һ���������λ�������ø�������m*10��
���磬n=1000,n�����λ=1000/(4-1)*10=1;
������pow(n,n)/pow(10,m-1);��������λk��
���������n^n�������λ��k�õ���������
Ҫ��a^n�����֪���� a^(n/2) �η��Ļ���������ƽ���Ϳ����ˡ���ô�������˼·�������÷��ε�˼���ˡ�
��д_pow������
*/


//eg4:������һ������(��������һ������)�������������12֮��������������鴦��
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include<string.h>

#define N 1000

using namespace std;

int main()
{
        char str[N];
        int len,i;

        while(cin>>str)
        {
            long long sum=0;
           len=strlen(str);
           for(i=0;i<len;i++)
           {
              sum=(sum*10+str[i]-'0')%12;
           }
           sum=(int)sum;
           cout<<sum<<endl;
       }
    return 0;
}

