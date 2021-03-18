#include <iostream>
//huffmanCoding.c
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define N 6

typedef struct huffNode
{
    unsigned int weight;   //Ȩ��
    unsigned int lchild,rchild,parent;  //�����ӽڵ�͸��ڵ�
}HTNode,*HuffTree;
typedef char **HuffCode;

//�ҳ��������޸��ڵ���Ȩֵ��С�������ڵ��±�,�ֱ���s1��s2����
void select(const HuffTree &HT,int n,int &s1,int &s2);
//HT:����������HC:���������룬w:������������ڵ��Ȩֵ��n:������������ڵ�ĸ���
void HuffmanCode(HuffTree &HT,HuffCode &HC,int *w,int n);


int main()
{
    int i;
    char key[N] = {'0','A','B','C','D','E'};//��0��Ԫ�ر�������
    int w[N] = {0,1,2,4,5,6}; //��0��Ԫ�ر�������
    HuffTree HT;
    HuffCode HC;
    HuffmanCode(HT,HC,w,N - 1);
    for ( i = 1; i < N; i++ )
	printf("%c:%s\n",key[i],HC[i]);

    printf("\n");
    return 0;
}




//�ҳ�������Ȩֵ��С�������ڵ��±�,�ֱ���s1��s2����
void select(const HuffTree &HT,int n,int &s1,int &s2)
{
    int i;
    s1 = s2 = 0;
    int min1 = INT_MAX;//��Сֵ��INT_MAX��<limits.h>�ж����
    int min2 = INT_MAX;//��Сֵ

    for ( i = 1; i <= n; ++i )
    {
	if ( HT[i].parent == 0 )
	{//ɸѡû�и��ڵ����С�ʹ�СȨֵ�±�
	    if ( HT[i].weight < min1 )
	    {//�������СֵС
		min2 = min1;
 		s2 = s1;
		min1 = HT[i].weight;
		s1 = i;
	    }
	    else if ( (HT[i].weight >= min1) && (HT[i].weight < min2) )
   	    {//������ڵ�����Сֵ����С�ڴ�Сֵ
		min2 = HT[i].weight;
 		s2 = i;
	    }
	    else
	    {//������ڴ�Сֵ����ʲô������
		;
	    }
	}
    }
}

//HT:����������HC:���������룬w:������������ڵ��Ȩֵ��n:������������ڵ�ĸ���
void HuffmanCode(HuffTree &HT,HuffCode &HC,int *w,int n)
{
    int s1;
    int s2;
    int m = 2 * n - 1;       //����֪��n���ڵ㹹��Ĺ���������2n-1���ڵ�
    int i,c,f,j;
    char *code;  //�ݴ�����
    HT = (HuffTree)malloc((m+1)*sizeof(HTNode));  //0��Ԫδʹ��


    for ( i = 1; i <= n; i++ )
        HT[i] = {w[i],0,0,0};//��ʼ��ǰn���ڵ�(�������������ԭʼ�ڵ�)

    for ( i = n + 1; i <= m; i++ )
	HT[i] = {0,0,0,0};  //��ʼ����n-1���ڵ�

    //������������
    for ( i = n + 1; i <= m; i++)
    {
	select(HT,i-1,s1,s2);//�ҳ�ǰi-1���ڵ���Ȩֵ��С�Ľڵ��±�
	HT[s1].parent = i;
	HT[s2].parent = i;
	HT[i].lchild = s1;
	HT[i].rchild = s2;
	HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    //����������
    HC = (char **)malloc((n)*sizeof(char *));
    //�ݴ����
    code = (char *)malloc(n*sizeof(char));//ʹ���˵�0��Ԫ
    for ( i = 1; i <= n; i++ )
    {
	for ( c = i, f = HT[c].parent, j = 0; f != 0; c = HT[c].parent, f = HT[c].parent,  j++ )
	{//��Ҷ��ɨ�赽��
	    if ( HT[f].lchild == c )
	    {
		code[j] = '0';
	    }
	    else if(HT[f].rchild == c)
	    {
		code[j] = '1';
	    }
 	    else
	    {//����ʲôҲ����
		;
	    }
	}
	code[j] = '\0';
   	HC[i] = (char *)malloc(strlen(code)*sizeof(char));
	strcpy(HC[i],code);
    }

}
