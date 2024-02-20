#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 9
#define INFINITY 65535
typedef int Pathmathirx[MAX];//用于储存最短路径点下标
typedef int ShortPathTable[MAX];//用于储存个点路径的权值和
//Dijkstra算法，求有向网络G的v0顶点到其余顶点v的最短路径p[v]和带权长度D[v]
//p[v]的值为前驱顶点的下标，D[v]表示从v0到v的最短路径长度和
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
			//举例：
			//0-1 1
			//0-2 5
			//1-2 3
   //此时，min是到原点最近的点
			//此时就把0-2的距离变成0-1 + 1-2的距离
			{
				(*d)[w] = min + G.arc[k][w];
				(*p)[w] = k;
			}
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
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (int i = 0; i < G->nume; i++)
	{
		printf("请输入边和权重：\n");
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