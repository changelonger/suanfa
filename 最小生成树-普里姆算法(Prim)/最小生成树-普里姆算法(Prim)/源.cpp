#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MAX 9
#define INFINITY 65535
struct MGraph
{
	int numv, nume, weight;
	int arc[MAX][MAX];
	int vexs[MAX];
};
void PrimMinTree(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAX];
	int lowcost[MAX];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for (i = 1; i < G.numv; i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < G.numv; i++)
	{
		min = INFINITY;
		j = 1; k = 0;
		while (j < G.numv)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("(%d,%d) ", adjvex[k], k);
		lowcost[k] = 0;
		for (j = 1; j < G.numv; j++)
			//找出来原本的lowcost和k顶点所各自所连接的顶点里面的较小值
			//比如，lowcost[2]=65535,而，arc[k][2]=18,就把lowcost里面的值改为18
			//这一步的目的是为了找到现有树上所有的顶点里面，与没有在树上的顶点边的权重的最小值
			//如果有重复，比如顶点3，有两个结点与他相关，则储存最小的
			//而adjvex的目的是储存父亲顶点，就是lowcost中最小值是和谁连起来的
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
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
	PrimMinTree(G);
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