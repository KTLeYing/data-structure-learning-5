#include<stdio.h>
#include<iostream>
#include<cstdlib>

using namespace std;


int main()
{
   int n,i;
   int array[25];
   //»òwhile(scanf("%d",&n)!=EOF)
   while(cin>>n)
   {
       for (i=0; i<n; i++)
          cin>>array[i];
       for (i=0; i<n; i++)
          cout<<array[i]<<" ";
       cout<<endl<<endl;
  }
   return 0;
}
