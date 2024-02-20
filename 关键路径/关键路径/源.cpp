#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#define MAX 10
struct Edgenode
{
	int adjvex;
	int weight;
	Edgenode* next;
};//边表节点
struct VertexNode
{
	int in;
	int data;
	Edgenode* firstedge;
};
typedef VertexNode Adjlist[MAX];
struct graphAdjlist
{
	Adjlist adjlist;
	int numv, nume;
};
typedef graphAdjlist* GraphAdjist;
int etv[MAX];
int ltv[MAX];//事件发生的最和最晚时间
int stack2[MAX];//储存拓扑排序的栈
int top2;
void CreatGraphAdjist(GraphAdjist G)
{
	printf("请输入结点数和边数：\n");
	scanf("%d%d", &G->numv, &G->nume);
	for (int i = 0; i < G->numv; i++)
	{
		G->adjlist[i].in = 0;
		G->adjlist[i].firstedge = NULL;
		G->adjlist[i].data = i;
	}
	for (int i = 0; i < G->nume; i++)
	{
		printf("请输入Vi->Vj中的i,j\n");
		int a = 0; int b = 0; int c;
		scanf("%d%d%d", &a, &b, &c);
		if (G->adjlist[a].firstedge == NULL || b > G->adjlist[a].firstedge->adjvex)
		{
			Edgenode* p = (Edgenode*)malloc(sizeof(Edgenode));
			p->weight = c;
			p->adjvex = b;
			p->next = G->adjlist[a].firstedge;
			G->adjlist[a].firstedge = p;
			G->adjlist[b].in++;
		}

		else
		{
			Edgenode* e = G->adjlist[a].firstedge;

			while (e->next)
			{
				if (b > e->next->adjvex)
				{
					Edgenode* p = (Edgenode*)malloc(sizeof(Edgenode));
					p->weight = c;
					p->adjvex = b;
					p->next = e->next;
					e->next = p;
					G->adjlist[b].in++;
				}
				else
					e = e->next;
			}
			if (e->next == NULL)
			{
				Edgenode* p = (Edgenode*)malloc(sizeof(Edgenode));
				p->weight = c;
				p->adjvex = b;
				e->next = p;
				G->adjlist[b].in++;
				p->next = NULL;
			}
		}
	}
}
int ToplogicalSort(GraphAdjist G)//求关键路径的拓扑排序
{
	Edgenode* e;
	int i, k, gettop;
	int top = 0;
	int count = 0;
	int stack[MAX] = { 0 };
	for (i = 0; i < G->numv; i++)
	{
		if (G->adjlist[i].in == 0)
			stack[++top] = i;
	}
	top2 = 0;
	for (i = 0; i < G->numv; i++)
		etv[i] = 0;
	while (top)
	{
		gettop = stack[top--];
		count++;
		stack2[++top2] = gettop;//把弹出栈顶的顶点压入新栈
		for (e = G->adjlist[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (!(--G->adjlist[k].in))
				stack[++top] = k;
			if (etv[gettop] + e->weight > etv[k])
				etv[k] = etv[gettop] + e->weight;
		}
	}
	return 0;
}
void CriticalPath(GraphAdjist G)
{
	Edgenode* e;
	int i, gettop, k, j;
	int ete, lte;
	ToplogicalSort(G);
	for (i = 0; i < G->numv; i++)
		ltv[i] = etv[G->numv - 1];
	while (top2)
	{
		gettop = stack2[top2--];
		for (e = G->adjlist[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if (ltv[k] - e->weight < ltv[gettop])//求各事件最迟发生事件LTV,较小值
				ltv[gettop] = ltv[k] - e->weight;
		}
	}
	for (j = 0; j < G->numv; j++)
	{
		for (e = G->adjlist[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			if (ete == lte)
				printf("<v%d,v%d>lenght:%d,",
					G->adjlist[j].data, G->adjlist[k].data, e->weight);
		}
	}
}
int main()
{
	graphAdjlist G;
	CreatGraphAdjist(&G);
	CriticalPath(&G);
	return 0;
}
//10 13
//0 2 4
//0 1 3
//1 4 6
//1 3 5
//2 5 7
//2 3 8
//3 4 3
//4 6 9
//4 7 4
//5 7 6
//6 9 2
//7 8 5
//8 9 3