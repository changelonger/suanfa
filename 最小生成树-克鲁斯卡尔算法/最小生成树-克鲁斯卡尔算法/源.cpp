#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <vector>
using namespace std;
#define MAX 20
#define INFINITY 65535
#include <algorithm>
struct Edge
{
	int begin;
	int end;
	int weight;
};
struct MGraph
{
	int numv;
	int nume;
	int arc[MAX][MAX];
};

bool compare(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}
int Find(int* parent, int f)
{
	while (parent[f] > 0)
		f = parent[f];
	return f;
}
void KruskalMinTree(MGraph G)
{
	int i = 0; int k = 0;
	Edge edges[MAX];
	int parent[MAX];
	for (i = 0; i < G.numv; i++)
	{
		for (int j = i; j < G.numv; j++)
		{
			if (G.arc[i][j] && G.arc[i][j] < INFINITY)
			{
				edges[k].weight = G.arc[i][j];
				edges[k].begin = i;
				edges[k].end = j;
				k++;
			}
		}
	}
	sort(edges, edges+G.nume, compare);
	for (i = 0; i < G.numv; i++)
		parent[i] = 0;
	for (i = 0; i < G.nume; i++)
	{
		int n = Find(parent, edges[i].begin);
		int m = Find(parent, edges[i].end);
		if (n != m)
		{
			parent[n] = m;
			printf("(%d,%d),%d ",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}

}
void CreatMGraph(MGraph* G)
{
	printf("请输入顶点数和边数：\n");
	scanf("%d%d", &G->numv, &G->nume);
	for (int i = 0; i < G->numv; i++)
	{
		for (int j = 0; j < G->numv; j++)
			G->arc[i][j] = INFINITY;
	}
	for (int i = 0; i < G->nume; i++)
	{
		getchar();
		int v, e, w;
		printf("请输入（vi,vj）的下标i,j，和权重w:\n");
		scanf("%d%d%d", &v, &e, &w);
		G->arc[v][e] = w;
		G->arc[e][v] = w;
	}
}
int main()
{
	MGraph G;
	CreatMGraph(&G);
	KruskalMinTree(G);
	return 0;
}
9 15
0 1 10
0 5 11
1 2 18
1 6 16
1 8 12
2 3 22
2 8 8
3 4 20
3 6 24
3 7 16
3 8 21
4 5 26
4 7 7
5 6 17
6 7 19