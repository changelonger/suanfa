#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#define MAX 40
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

int ToplogicalSort(GraphAdjist Gl)
{
	Edgenode* e;
	int i, k, gettop;

	int top = 0;
	int count = 0;
	int stack[MAX];
	for (i = 0; i < Gl->numv; i++)
	{
		if (Gl->adjlist[i].in == 0)
		{
			stack[++top] = i;
			
		}
	}
	while(top)
	{
		gettop = stack[top--];
		printf("%d->", Gl->adjlist[gettop].data);
		count++;
		for (e = Gl->adjlist[gettop].firstedge;e;e = e->next)
		{
			k = e->adjvex;
			if (!(--Gl->adjlist[k].in))
			stack[++top] = k;
		}
	}
	if (count < Gl->numv)
		return 0;
	else
		return 1;
}
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
		scanf("%d%d%d", &a, &b,&c);
		if (G->adjlist[a].firstedge == NULL||b>G->adjlist[a].firstedge->adjvex)
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
					e->next= p;
					G->adjlist[b].in++;
				}
				else
					e = e->next;
			}
			if (e->next==NULL)
			{
				Edgenode* p = (Edgenode*)malloc(sizeof(Edgenode));
				p->weight = c;
				p->adjvex = b;
				e->next= p;
				G->adjlist[b].in++;
				p->next = NULL;
			}
		}
	}
}
int main()
{
	graphAdjlist G;
	CreatGraphAdjist(&G);
	ToplogicalSort(&G); 
	return 0;
}
/*
13 20
0 11
1 4
2 5
0 5
1 8
2 6
0 4
1 2
2 9
3 2
3 13
4 7
5 12 
5 8
6 5
8 7
9 11
9 10
10 13
12 9
*/

