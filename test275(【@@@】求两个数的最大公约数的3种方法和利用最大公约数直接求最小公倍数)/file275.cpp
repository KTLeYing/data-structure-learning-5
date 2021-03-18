#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
/*
//法1:辗转相除法
int main()
{
    int m,n,temp,z,m1,n1;  //定义两个整数
    cout<<"请输入两个整数(用空格隔开):"<<endl;
    while(cin>>m>>n)
    {
        m1=m;
        n1=n;
        if(m!=0&&n!=0)  //判断输入中是否有零值
        {
            do
            {
                temp=m%n;
                m=n;
                n=temp;
            }
            while(temp);
             cout<<"最大公约数为："<<m<<endl;
             z=(m1*n1)/m;
             cout<<"最小公倍数为:"<<z<<endl<<endl;
        }
        else
            cout<<"输入有误，请重新输入"<<endl;  //无法求公约数则返回
    }
}
*/
//或
/*
int main()
{
    int a,b,a1,b1,z,temp;  //定义两个整数
    cout<<"请输入两个整数(用空格隔开):"<<endl;
    while(cin>>a>>b)
    {
        a1=a;
        b1=b;
        if(a<b)
        {
          //交换两个数，使大数放在a上
           temp=a;
           a=b;
           b=temp;
        }
        while(b!=0)
        {
           //利用辗除法，直到b为0为止
          temp=a%b;
          a=b;
          b=temp;
        }
       cout<<"最大公约数为："<<a<<endl;
       z=(a1*b1)/a;
       cout<<"最小公倍数为:"<<z<<endl<<endl;
    }
}
*/
//或
int GCD(int n,int m)//最大公约数
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

int LCM(int n,int m)//最小公倍数
{
    int z;
    z=n*m/GCD(n,m);
    return z;
}

int main()
{
    int m,n,x,y;
    cout<<"请输入两个数:";
    cin>>n>>m;
    x=GCD(n,m);
    y=LCM(n,m);
    cout<<"最大公因数为:"<<x<<endl;
    cout<<"最小公倍数为:"<<y<<endl;
}


/*
//法2:穷举法（用for循环）
int main()
{
    int j=0;  //定义一个标记
    int a,b,z;  //定义两个整数
    cout<<"请输入两个整数:"<<endl;
    while(cin>>a>>b)
    {
        if(a == 0 || b == 0)
            cout<<"输入含0数字，请重新输入"<<endl;
        else
        {
            for(j=a; ;j--)  //反复执行j
            {
                if(a%j == 0 && b%j == 0)  //若a、b能同时被j整除，j为最大公约数
                    break;
            }
            cout<<"最大公约数为:"<<j<<endl;
            z=(a*b)/j;
            cout<<"最小公倍数为:"<<z<<endl<<endl;
        }
    }
}
*/

/*
//法3:辗转相减法
int main()
{
    int a,b,a1,b1,z;
    cout<<"请输入两个正整数:"<<endl;
    while(cin>>a>>b)
    {
        a1=a;
        b1=b;
        if(a == 0 && b == 0)
            cout<<"输入含0数字，请重新输入"<<endl;  //检查是否输入含0数字
        else
        {
            while(a!=b)
            {
                if(a>b)  //当a大于b时，用a减去b
                {
                    a=a-b;
                }
                else
                {
                    b=b-a;  //当b大于a时，用b减去a
                }
            }
            cout<<"最大公约数为:"<<a<<endl;  //直到a=b时，这时的a（或b）为最大公约数
            z=(a1*b1)/a;
            cout<<"最小公倍数为:"<<z<<endl<<endl;
        }
    }
}
*/
