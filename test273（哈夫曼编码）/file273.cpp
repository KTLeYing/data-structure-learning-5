#include <iostream>
//huffmanCoding.c
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define N 6

typedef struct huffNode
{
    unsigned int weight;   //权重
    unsigned int lchild,rchild,parent;  //左右子节点和父节点
}HTNode,*HuffTree;
typedef char **HuffCode;

//找出数组中无父节点且权值最小的两个节点下标,分别用s1和s2保存
void select(const HuffTree &HT,int n,int &s1,int &s2);
//HT:哈夫曼树，HC:哈夫曼编码，w:构造哈夫曼树节点的权值，n:构造哈夫曼树节点的个数
void HuffmanCode(HuffTree &HT,HuffCode &HC,int *w,int n);


int main()
{
    int i;
    char key[N] = {'0','A','B','C','D','E'};//第0个元素保留不用
    int w[N] = {0,1,2,4,5,6}; //第0个元素保留不用
    HuffTree HT;
    HuffCode HC;
    HuffmanCode(HT,HC,w,N - 1);
    for ( i = 1; i < N; i++ )
	printf("%c:%s\n",key[i],HC[i]);

    printf("\n");
    return 0;
}




//找出数组中权值最小的两个节点下标,分别用s1和s2保存
void select(const HuffTree &HT,int n,int &s1,int &s2)
{
    int i;
    s1 = s2 = 0;
    int min1 = INT_MAX;//最小值，INT_MAX在<limits.h>中定义的
    int min2 = INT_MAX;//次小值

    for ( i = 1; i <= n; ++i )
    {
	if ( HT[i].parent == 0 )
	{//筛选没有父节点的最小和次小权值下标
	    if ( HT[i].weight < min1 )
	    {//如果比最小值小
		min2 = min1;
 		s2 = s1;
		min1 = HT[i].weight;
		s1 = i;
	    }
	    else if ( (HT[i].weight >= min1) && (HT[i].weight < min2) )
   	    {//如果大于等于最小值，且小于次小值
		min2 = HT[i].weight;
 		s2 = i;
	    }
	    else
	    {//如果大于次小值，则什么都不做
		;
	    }
	}
    }
}

//HT:哈夫曼树，HC:哈夫曼编码，w:构造哈夫曼树节点的权值，n:构造哈夫曼树节点的个数
void HuffmanCode(HuffTree &HT,HuffCode &HC,int *w,int n)
{
    int s1;
    int s2;
    int m = 2 * n - 1;       //容易知道n个节点构造的哈夫曼树是2n-1个节点
    int i,c,f,j;
    char *code;  //暂存编码的
    HT = (HuffTree)malloc((m+1)*sizeof(HTNode));  //0单元未使用


    for ( i = 1; i <= n; i++ )
        HT[i] = {w[i],0,0,0};//初始化前n个节点(构造哈夫曼树的原始节点)

    for ( i = n + 1; i <= m; i++ )
	HT[i] = {0,0,0,0};  //初始化后n-1个节点

    //构建哈夫曼树
    for ( i = n + 1; i <= m; i++)
    {
	select(HT,i-1,s1,s2);//找出前i-1个节点中权值最小的节点下标
	HT[s1].parent = i;
	HT[s2].parent = i;
	HT[i].lchild = s1;
	HT[i].rchild = s2;
	HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    //哈夫曼编码
    HC = (char **)malloc((n)*sizeof(char *));
    //暂存编码
    code = (char *)malloc(n*sizeof(char));//使用了第0单元
    for ( i = 1; i <= n; i++ )
    {
	for ( c = i, f = HT[c].parent, j = 0; f != 0; c = HT[c].parent, f = HT[c].parent,  j++ )
	{//从叶子扫描到根
	    if ( HT[f].lchild == c )
	    {
		code[j] = '0';
	    }
	    else if(HT[f].rchild == c)
	    {
		code[j] = '1';
	    }
 	    else
	    {//否则什么也不做
		;
	    }
	}
	code[j] = '\0';
   	HC[i] = (char *)malloc(strlen(code)*sizeof(char));
	strcpy(HC[i],code);
    }

}
