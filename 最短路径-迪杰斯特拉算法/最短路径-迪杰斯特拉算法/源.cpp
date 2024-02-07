#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 9
#define INFINITY 65535
typedef int Pathmathirx[MAX];//���ڴ������·�����±�
typedef int ShortPathTable[MAX];//���ڴ������·����Ȩֵ��
//Dijkstra�㷨������������G��v0���㵽���ඥ��v�����·��p[v]�ʹ�Ȩ����D[v]
//p[v]��ֵΪǰ��������±꣬D[v]��ʾ��v0��v�����·�����Ⱥ�
struct MGraph
{
	int arc[MAX][MAX];
	int nume, numv;
};
struct Edge
{
	int begin, end, weight;
};
void hortestPathDijkstra(MGraph G, int V0, Pathmathirx* p, ShortPathTable* d)
{
	int v, w, k, min;
	int final[MAX];
	for (v = 0; v < G.numv; v++)
	{
		final[v] = 0;
		(*d)[v] = G.arc[V0][v];
		(*p)[v] = 0;
	}
	(*d)[V0] = 0;
	final[V0] = 1;
	for (v = 1; v < G.numv; v++)
	{
		min = INFINITY;
		for (w = 0; w < G.numv; w++)
		{
			if (!final[w] && (*d)[w] < min)
			{
				k = w;
				min = (*d)[w];
			}
		}
		final[k] = 1;
		for (w = 0; w < G.numv; w++)
		{
			if (!final[w] && (min + G.arc[k][w] < (*d)[w]))
			//������
			//0-1 1
			//0-2 5
			//1-2 3
			//��ʱ�Ͱ�0-2�ľ�����0-1 + 1-2�ľ���
			{
				(*d)[w] = min + G.arc[k][w];
				(*p)[w] = k;
			}
		}
	}
	
}
void CreatMGraph(MGraph* G)
{
	printf("�����붥�����ͱ�����\n");
	scanf("%d%d", &G->numv, &G->nume);
	for (int i = 0; i < G->numv; i++)
	{
		for (int j = 0; j < G->numv; j++)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < G->nume; i++)
	{
		printf("������ߺ�Ȩ�أ�\n");
		getchar();
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		G->arc[a][b] = w;
		G->arc[b][a] = w;
	}
}
int main()
{
	MGraph G;
	CreatMGraph(&G);
	Pathmathirx p;
	ShortPathTable d;
	hortestPathDijkstra(G, 0, &p,&d);
	return 0;
}
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4