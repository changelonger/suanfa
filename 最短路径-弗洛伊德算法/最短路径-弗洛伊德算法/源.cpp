#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 10
#define INFINITY 65535
typedef int Pathmatirx[MAX][MAX];
typedef int ShortPathTable[MAX][MAX];
struct MGraph
{
	int numv, nume;
	int arc[MAX][MAX];
};
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

		getchar();
		printf("������ߺ�Ȩ�أ�\n");
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		G->arc[a][b] = w;
		G->arc[b][a] = w;

	}
}
void ShortestPathFloyd(MGraph G, Pathmatirx* p, ShortPathTable* d)
{

	int v, w, k;
	for (v = 0; v < G.numv; v++)
	{
		for (w = 0; w < G.nume; w++)
		{
			(*d)[v][w] = G.arc[v][w];
			(*p)[v][w] = w;
		}
	}
	for (k = 0; k < G.numv; k++)
	{
		for (v = 0; v < G.numv; v++)
		{
			for (w = 0; w < G.numv; w++)
			{
				if ((*d)[v][w] > (*d)[v][k] + (*d)[k][w])
				{
					(*d)[v][w] = (*d)[v][k] + (*d)[k][w];
					(*p)[v][w] = (*p)[v][k];
				}
			}
		}
	}
}
void PlayShortestPath(MGraph G, int begin, int end, Pathmatirx* p, ShortPathTable* d)
{
	
	printf("��Դ��%d���յ�%d���·���ǣ�\n", begin, end);
	printf("%d", begin);
	int k = (*p)[begin][end];
	int s = (*d)[begin][end];
	while (k != end)
	{
		printf("->%d", k);
		k = (*p)[k][end];
		s+=(*d)[k][end];
	}
	printf("->%d\n", end);
	printf("��Դ��%d���յ�%d���·�����ܾ����ǣ�%d",begin,end,s);
}
int main()
{
	MGraph G;
	CreatMGraph(&G);
	Pathmatirx p;
	ShortPathTable s ;
	ShortestPathFloyd(G, &p, &s);
	PlayShortestPath(G, 0, 8, &p, &s);
	return 0;
}