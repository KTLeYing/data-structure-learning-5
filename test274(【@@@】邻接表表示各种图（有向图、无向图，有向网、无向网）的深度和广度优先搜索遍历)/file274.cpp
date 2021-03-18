#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20//��󶥵����

typedef int Status;
typedef int InfoType;
typedef char VertexType;

bool visited[MAX_VERTEX_NUM];

typedef struct ArcNode {
	int adjvex;//�û���ָ��Ķ���λ��
	struct ArcNode *nextarc;//ָ����һ������ָ��
	InfoType info;//�û������Ϣ��ָ��
}ArcNode;


typedef struct VNode {
	VertexType data;//������Ϣ
	ArcNode *firstarc;//ָ���һ�������ö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
	int kind;//ͼ�������־
}ALGraph;

int LocateVex(ALGraph G, char v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v)
			return i;
	}
	return -1;
}
/*
   �����ڽӱ�洢��ʾ����������ͼG
*/
Status CreateUDG(ALGraph &G)
{
	int i, j, k, IncInfo;
	ArcNode *pi, *pj;
	char v1, v2;
	cout << "���붥����G.vexnum:";
	cin >> G.vexnum;
	cout << "�������G.arcnum:";
	cin >> G.arcnum;
	getchar();
	for (i = 0; i < G.vexnum; ++i)
	{
		cout << "���붥��G.vertices[" << i << "].data:";
		cin >> G.vertices[i].data;
		getchar();
		//��ʼ������ͷָ��Ϊ��
		G.vertices[i].firstarc = NULL;
	}
	/*
	   ������߲������ڽӱ�
	*/
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "�������" << k + 1 << "���ߵ���������:"<<endl;
		//����һ���ߵ������յ�
		cin >> v1;
		cin >> v2;
		getchar();
		//ȷ��V1��V2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode))))
			exit(OVERFLOW);
		//�Ի���㸳�ڽӵ�"λ��"��Ϣ
		pi->adjvex = j;
		pi->info = 0;
		//��������G.vertices[i]
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;

		if (!(pj = (ArcNode *)malloc(sizeof(ArcNode))))
			exit(OVERFLOW);
		//�Ի���㸳�ڽӵ�"λ��"��Ϣ
		//��������G.vertices[j]
		pj->adjvex = i;
		pj->info = 0;
		pj->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = pj;
	}//for
	return OK;
}//CreateUDG

//����ͼ
Status CreateDG(ALGraph &G)
{
	int i, j, k, IncInfo;
	ArcNode *pi, *pj;
	char v1, v2;
	cout << "���붥����G.vexnum:";
	cin >> G.vexnum;
	cout << "�������G.arcnum:";
	cin >> G.arcnum;
	getchar();
	for (i = 0; i < G.vexnum; ++i)
	{
		cout << "���붥��G.vertices[" << i << "].data:";
		cin >> G.vertices[i].data;
		getchar();
		//��ʼ������ͷָ��Ϊ��
		G.vertices[i].firstarc = NULL;
	}
	/*
	������߲������ڽӱ�
	*/
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "�������" << k + 1 << "���ߵ���������:" << endl;
		//����һ���ߵ������յ�
		cin >> v1;
		cin >> v2;
		getchar();
		//ȷ��V1��V2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode))))
			exit(OVERFLOW);
		//�Ի���㸳�ڽӵ�"λ��"��Ϣ
		pi->adjvex = j;
		pi->info = 0;
		//��������G.vertices[i]
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;
	}//for
	return OK;
}//CreateDG
//������
Status CreateDN(ALGraph &G)
{
	int i, j, k, IncInfo;
	ArcNode *pi, *pj;
	char v1, v2;
	cout << "���붥����G.vexnum:";
	cin >> G.vexnum;
	cout << "�������G.arcnum:";
	cin >> G.arcnum;
	cout << "�����Ƿ���Info��Ϣ��0��û�У�1���У�";
	cin >> IncInfo;
	getchar();
	for (i = 0; i < G.vexnum; ++i)
	{
		cout << "���붥��G.vertices[" << i << "].data:";
		cin >> G.vertices[i].data;
		getchar();
		//��ʼ������ͷָ��Ϊ��
		G.vertices[i].firstarc = NULL;
	}
	/*
	������߲������ڽӱ�
	*/
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "�������" << k + 1 << "���ߵ���������������ߵ�Ȩֵ:" << endl;
		//����һ���ߵ������յ�
		cin >> v1;
		cin >> v2;
		cin >> IncInfo;
		getchar();
		//ȷ��V1��V2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode))))
			exit(OVERFLOW);
		//�Ի���㸳�ڽӵ�"λ��"��Ϣ
		pi->adjvex = j;
		//��������G.vertices[i]
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;

		pi->info = IncInfo;
	}//for
	return OK;
}//CreateDN
//������
Status CreateUDN(ALGraph &G)
{
	int i, j, k, IncInfo;
	ArcNode *pi, *pj;
	char v1, v2;
	cout << "���붥����G.vexnum:";
	cin >> G.vexnum;
	cout << "�������G.arcnum:";
	cin >> G.arcnum;
	cout << "�����Ƿ���Info��Ϣ��0��û�У�1���У�";
	cin >> IncInfo;
	getchar();
	for (i = 0; i < G.vexnum; ++i)
	{
		cout << "���붥��G.vertices[" << i << "].data:";
		cin >> G.vertices[i].data;
		getchar();
		//��ʼ������ͷָ��Ϊ��
		G.vertices[i].firstarc = NULL;
	}
	/*
	������߲������ڽӱ�
	*/
	for (k = 0; k < G.arcnum; ++k)
	{
		cout << "�������" << k + 1 << "���ߵ���������������ߵ�Ȩֵ:" << endl;
		//����һ���ߵ������յ�
		cin >> v1;
		cin >> v2;
		cin >> IncInfo;
		getchar();
		//ȷ��V1��V2��G�е�λ��
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (!(pi = (ArcNode *)malloc(sizeof(ArcNode))))
			exit(OVERFLOW);
		//�Ի���㸳�ڽӵ�"λ��"��Ϣ
		pi->adjvex = j;
		//��������G.vertices[i]
		pi->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = pi;
		pi->info = IncInfo;
		if (!(pj = (ArcNode *)malloc(sizeof(ArcNode))))
			exit(OVERFLOW);
		//�Ի���㸳�ڽӵ�"λ��"��Ϣ
		pj->adjvex = i;
		//��������G.vertices[i]
		pj->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = pi;
		pj->info = IncInfo;
	}//for
	return OK;
}//CreateUDN


Status CreateGraph(ALGraph &G)
{
	cout << "������ͼ�����ࣺ0��ʾDG(����ͼ)��1��ʾDN(������)��2��ʾUDG(����ͼ)��3��ʾUDN(������)" << endl;
	cin >> G.kind;
	switch (G.kind)
	{
	case 0:
		return CreateDG(G);
	case 1:
		return CreateDN(G);
	case 2:
		return CreateUDG(G);
	case 3:
		return CreateUDN(G);
	default:
		return ERROR;
	}
}

void list(ALGraph G)
{
	int i;
	ArcNode *p;
	cout << "����ڽӱ���0��������Ȩֵ����" << endl;
	for (i = 0; i < G.vexnum; ++i)
	{
		cout << i << "��" << G.vertices[i].data;
		p = G.vertices[i].firstarc;
		while (p)
		{
			cout << setw(3) << p->adjvex;
			cout << "(" <<p->info<< ")";
			p = p->nextarc;
		}
		cout << endl;
	}
}


void DFS(ALGraph G, int v)
{
	ArcNode *p;
	int w;
	visited[v] = TRUE;
	cout << G.vertices[v].data << " ";

	for (p = G.vertices[v].firstarc; p; p = p->nextarc)
	{
		w = p->adjvex;
		if (!visited[w])//��v����δ���ʵ��ڽӶ���w�ݹ����DFS
			DFS(G, w);
	}
}
//������ȱ���
void DFSTraverse(ALGraph G)
{
	int v;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])
		{
			DFS(G, v);
			cout << endl;
		}
	}
}

void BFSTraverse(ALGraph G)
{
	int v,w;
	//��������
	int front=0, rear = 0;
	VNode Queue[MAX_VERTEX_NUM];
	ArcNode *p;

	//��ʼ����־����
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])//v��δ����
		{
			visited[v] =true;
			cout << G.vertices[v].data<<" ";
			Queue[++rear] = G.vertices[v];//v�����
			while (front != rear)//�ж϶����Ƿ�Ϊ��
			{
				VNode u = Queue[++front];//��ͷԪ�س����У�������u
				//cout << endl;
				/*
				�жϸý��ĺ������,���ڼ�����������
				*/
				for (p = u.firstarc; p; p = p->nextarc)
				{
					w = p->adjvex;
					if (!visited[w])
					{
						visited[w] = true;
						cout << G.vertices[w].data << " ";
						Queue[++rear] = G.vertices[w];
					}//if
				}//for
			}//while
		}//if
	}//for
}//BFSTraverse

int main()
{
	ALGraph G;
	CreateGraph(G);
	list(G);
	//������ȱ���ͼ
	cout << "������ȱ�����";
	DFSTraverse(G);
	cout << endl;
	//������ȱ���
	cout << "������ȱ�����";
	BFSTraverse(G);
	cout<<endl;
	system("pause");
}
