#include <stdio.h>
struct queue      //定义队列的结构体
{
    int data[1000];
	int head;
	int tail;
};
struct stack      //定义栈的结构体
{
    int data[10];
	int top;
};
int main()
{
    struct queue q1,q2;       //定义队列的结构变量
	struct stack s;            //定义栈的结构变量
	int book[10];
	int i,t;
	q1.head=0;         //队列初始化
	q1.tail=0;
	q2.head=0;
	q2.tail=0;
	s.top=0;           //栈的初始化
	for(i=1;i<=9;i++)
		book[i]=0;          //初始化用来标记在桌上的牌的数组
	printf("please input person1 numbers:");
	for(i=0;i<=5;i++)           //向队列插入6个数，person1手上的牌
	{
	    scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	printf("please input person2 numbers:");
	for(i=0;i<=5;i++)          //向队列插入6个数，person2手上的牌
	{
	   scanf("%d",&q2.data[q2.tail]);
	   q2.tail++;
	}
	while(q1.head<q1.tail && q2.head<q2.tail)              //队列不为空时执行
	{
	   t=q1.data[q1.head];               //person1出牌
	   if(book[t]==0)                //表明桌上没有t的牌
	   {                              //person1此轮没有赢牌
	      q1.head++;                //person1打出第一张牌，第一张牌出队
		  s.top++;
		  s.data[s.top]=t;                    //打出的牌放到桌面，即入栈
		  book[t]=1;                     //标记桌面有t的牌
	   }
	   else
	   {                       //person1此轮可以赢牌
	       q1.head++;            //person1打出第一张牌，第一张牌出队
		   q1.data[q1.tail]=t;     //紧接着把打出的牌放到手中牌的末尾
		   q1.tail++;
		   while(s.data[s.top]!=t)      //把桌上可以赢得牌依次放到手中牌的末尾
		   {
		      book[s.data[s.top]]=0;        //取消标记
			  q1.data[q1.tail]=s.data[s.top];          //依次放到队尾
			  q1.tail++;
			  s.top--;                 //栈中少了一张牌，所以栈顶要减1
		   }
		   book[s.data[s.top]]=0;   //收回桌上为t的牌（因为赢的牌是：两张相同的牌及其中间夹着的牌，所以最后取完那些不同的牌后，还要另外取出最后一张与t相同的牌）
		   q1.data[q1.tail]=s.data[s.top];     
		   q1.tail++;
		   s.top--;
	   }
	   if(q1.head==q1.tail)      //person1手中的牌已经打完，游戏结束，跳出循环
		   break;
       t=q2.data[q2.head];     //person2出牌
	   if(book[t]==0)      //表明桌上没有t的牌
	   {                    //person2此轮没有赢牌
	      q2.head++;
		  s.top++;
		  s.data[s.top]=t;     //打出的牌放到桌面，即入栈
		  book[t]=1;            //标记桌面有t的牌
	   }
	   else
	   {                      //person2此轮可以赢牌
	       q2.head++;               //person2打出第一张牌，第一张牌出队
		   q2.data[q2.tail]=t;     //紧接着把打出的牌放到手中牌的末尾
		   q2.tail++;
		   while(s.data[s.top]!=t)          //把桌上可以赢得牌依次放到手中牌的末尾
		   {
		      book[s.data[s.top]]=0;            //取消标记
			  q2.data[q2.tail]=s.data[s.top];              //依次放到队尾
			  q2.tail++;               
			  s.top--;                              //栈中少了一张牌，所以栈顶要减1
		   }                     
		   book[s.data[s.top]]=0;  //收回桌上为t的牌（因为赢的牌是：两张相同的牌及其中间夹着的牌，所以最后取完那些不同的牌后，还要另外取出最后一张与t相同的牌）
		   q2.data[q2.tail]=s.data[s.top];
		   q2.tail++;
		   s.top--;
	   }
	}
	
	if(q2.head==q2.tail)            //若队列2为空，则是person1赢
	{
	    printf("person1 win\n");
		printf("person1 的牌是:");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0)
		{
		   printf("\n桌上的牌是:");
		   for(i=1;i<=s.top;i++)
			   printf(" %d",s.data[i]);
		}
		else
			printf("\n桌上已经没牌了");
	}
	else
	{                                //若队列1为空，则是person1赢
	    printf("person2 win\n");
		printf("person2 的牌是:");
		for(i=q2.head;i<=q2.tail-1;i++)
			printf(" %d",q2.data[i]);
		if(s.top>0)
		{
		   printf("\n桌上的牌是:");
		   for(i=1;i<=s.top;i++)
			   printf(" %d",s.data[i]);
		}
		else
			printf("\n桌上已经没牌了");
	}
	return 0;
}