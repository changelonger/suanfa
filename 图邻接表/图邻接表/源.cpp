#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//�ڽӱ�
#include<stdlib.h>
typedef char Vertex;
typedef int Edge;
#define MAX 10
struct Edgenode//�߱���
{
	int adjvex;
	int weight;
	struct Edgenode* next;
};
typedef Edgenode* fistedge;
struct Vertexnode
{
	Vertex data;
	Edgenode* fistedge;//�߱�ͷָ�룻
};
typedef Vertexnode AdjList[MAX];
struct GraphAdjList
{
	AdjList adjList;
	int numv, nume;//ͼ�ж������ͱ���
};

int visited[MAX];
//G��ͼ��ָ�룬GrephAdjList����ͼ���������ڽӱ����ʽչʾ
//Vertexnode����ڵ㣬������AdjList�Ǳ�����顣����Ԫ����һ��������
void CreatALGraph(GraphAdjList* G)
{
	//��������
	/*4 5
		A B C D
		0 1
		0 3
		0 2*/
	int i, j, k;
	Edgenode* e;
	printf("���붥�����ͱ�����\n");
	scanf("%d%d", &G->numv, &G->nume);

	for (i = 0; i < G->numv; i++)//���붥����Ϣ�����������
	{
		getchar();
		scanf("%c", &G->adjList[i].data);
		G->adjList[i].fistedge = NULL;
	}
	for (k = 0; k < G->nume; j++)//�����߱���������ͼ��
	{
		getchar();
		scanf("%d%d", &i, &j);//����vi,vj�Ķ�����ţ�
		e = (Edgenode*)malloc(sizeof(Edgenode));
		e->weight = 1;
		//��С����
		if (G->adjList[i].fistedge == NULL || j < G->adjList[i].fistedge->adjvex)//Ϊ�գ������һ����ֱ�Ӳ壬���߱Ⱥ����С 
		{
			e->adjvex = j;
			e->next = G->adjList[i].fistedge;
			G->adjList[i].fistedge = e;//ͷ�巨
		}
		else
		{
			Edgenode* p = G->adjList[i].fistedge;
			while (p->next && j > p->next->adjvex)
			{
				p = p->next;
			}
			e->adjvex = j;
			e->next = p->next;
			p->next = e;//ͷ�巨
		}
	}
}
void DFS2(GraphAdjList Gl, int i)
{
	Edgenode* p;
	visited[i] = 1;
	printf("%c ", Gl.adjList[i].data);
	p = Gl.adjList[i].fistedge;
	while (p)
	{
		if (!visited[p->adjvex])
			DFS2(Gl, p->adjvex);
		p = p->next;
	}
}
//��һ���������߽ڵ�ָ�룬���Ұѵ��õĶ�������Ϊ1����ʾ��������Ȼ����в���
//�ڶ�������pָ�����ֵΪ��ǰ�ڵ��Ӧ�ĵ�һ���߽ڵ�
//���������߽ڵ㿴�Ƿ��������û�еĻ������
void DFS2Traverse(GraphAdjList Gl)
{
	for (int i = 0; i < Gl.numv; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < Gl.numv; i++)
	{
		if (!visited[i])
			DFS2(Gl, i);
	}
}
//��һ������ʼ��visited[i]���飬ȫ������Ϊ0
//�ڶ������ӵ�һ����ʼ������visited����
//��������û�����������͵���������㷨


void BFSTraverse(GraphAdjList Gl)
{
	int i;
	Edgenode* p;
	sqqueue q;
	for (i = 0; i < Gl.numv; i++)
		visited[i] = 0;
	initqueue(&q);
	for (i = 0; i < Gl.numv; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			enqueue(&q, i);
			while (q.front != q.rear)
			{
				dequeue(&q, &i);
				p = Gl.adjList[i].fistedge;
				while (p)
				{
					if (visited[p->adjvex] == 0)
					{
						visited[p->adjvex] = 1;
						printf("%c ", Gl.adjList[p->adjvex].data);
						enqueue(&q, i);
					}
					p = p->next;
				}
			}
		}
	}
}