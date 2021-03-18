#include <stdio.h>
int main()
{ 
    int head,tail,q[100],i,n;
	printf("please input all the number:");
	scanf("%d",&n);
	printf("please input the numbers:");
    for(i=0;i<n;i++)            //输入并初始化队列
		scanf("%d",&q[i]);
	head=0;
	tail=n;       //tail指向队尾的后一个位置
	while(head<tail)
	{
	   printf("%d ",q[head]);    //打印队首
	   head++;       //队首出队
	   q[tail]=q[head];          //新队首的数添加到队尾
	   tail++;     //再将队首出队
	   head++;
	}
	return 0;
}

  //队首出队->新队首加到队尾->再新的队首出队....(又重新来一轮)