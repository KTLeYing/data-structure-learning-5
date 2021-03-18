/*
//eg1:求n的阶乘模上(n+2)的值
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>

using namespace std;

int a[100005];
int w = 1;//位数初始为1

string fac(int n)//求阶乘
{

    string str;
    for(int z = 1; z <= n; z++)
    {
        int x = 0;
        for(int i = 1; i <= w; ++i)
        {
           a[i] = a[i]*z + x;//算出相乘后的结果
           x = a[i]/10;//如果x=0说明a[i]<10,即无进位；若x>0则有进位
           a[i] = a[i]%10;//将i位的数字算出来，其实是取整
        }
        while (x > 0)//有进位
        {
           w++;//位数+1
           a[w] = x%10;//进位的数字
           x = x/10;
        }
    }
    for(int j=w;j>=1;--j)
        str+= a[j]+'0';//将数组中的内容放到string里面
    cout<<str<<endl;
    return str;
}

int mod(string str,int n)//求余数
{
    int l,y;
    l=str.length();
    y=(str[0]-'0')%n;//同余定理
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
//eg2:求整数n的阶乘除以(n-m)的余数是多少
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
/*说明：
n! = 1*2*3*...*(n-m-1)*(n-m)*(n-m+1)*...*(n-1)*n
n!%(n-m) = 0
*/

/*
//eg3:一个整数n,求n^n(n的n次方)的最高位数字k(即最左边的一位)，求出k之后再求n^n除以k的余数。
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int _pow(int a,long long n,int m)
{// 求a^n%m得到的余数
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
      m=log10(pow(n,n))+1;//先计算出n^n的长度
      k=pow(n,n)/pow(10,m-1);//用n^n除以10的n^n位数减1次方，得到最高位
      cout<<"Case "<<i<<":";
      cout<<k<<" "<<_pow(n, n, k)<<endl<<endl;
   }
}
/*
/*说明：
步骤1：先求出该n^n的最高位数。
在此处涉及到两个库函数
C 库函数 double pow(double x, double y) 返回 x 的 y 次幂，即 x^y。
C 库函数 double log10(double x) 返回 x 的常用对数（基数为 10 的对数）。
利用pow()函数可求得n^n，再利用log10求得其位数。
假设n^n的位数为m
求一个数的最高位，可以用该数除以m*10。
例如，n=1000,n的最高位=1000/(4-1)*10=1;
所以用pow(n,n)/pow(10,m-1);可求得最高位k。
步骤二：求n^n除以最高位数k得到的余数。
要求a^n，如果知道了 a^(n/2) 次方的话，再来个平方就可以了。那么按照这个思路就能运用分治的思想了。
编写_pow函数，
*/


//eg4:求输入一个整数(该整数是一个大数)，输出该数除以12之后的余数【用数组处理】
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

