#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
//邻接表
#include<stdlib.h>
typedef char Vertex;
typedef int Edge;
#define MAX 10
struct Edgenode//边表结点
{
	int adjvex;
	int weight;
	struct Edgenode* next;
};
typedef Edgenode* fistedge;
struct Vertexnode
{
	Vertex data;
	Edgenode* fistedge;//边表头指针；
};
typedef Vertexnode AdjList[MAX];
struct GraphAdjList
{
	AdjList adjList;
	int numv, nume;//图中顶点数和边数
};

int visited[MAX];
//G是图的指针，GrephAdjList就是图，不过以邻接表的形式展示
//Vertexnode顶点节点，重命名AdjList是变成数组。里面元素是一个个顶点
void CreatALGraph(GraphAdjList* G)
{
	//测试数据
	/*4 5
		A B C D
		0 1
		0 3
		0 2*/
	int i, j, k;
	Edgenode* e;
	printf("输入顶点数和边数：\n");
	scanf("%d%d", &G->numv, &G->nume);

	for (i = 0; i < G->numv; i++)//输入顶点信息，建立顶点表
	{
		getchar();
		scanf("%c", &G->adjList[i].data);
		G->adjList[i].fistedge = NULL;
	}
	for (k = 0; k < G->nume; j++)//建立边表，假设有向图；
	{
		getchar();
		scanf("%d%d", &i, &j);//输入vi,vj的顶点序号；
		e = (Edgenode*)malloc(sizeof(Edgenode));
		e->weight = 1;
		//从小到大
		if (G->adjList[i].fistedge == NULL || j < G->adjList[i].fistedge->adjvex)//为空，小于第一个，直接插
		{
			e->adjvex = j;
			e->next = G->adjList[i].fistedge;
			G->adjList[i].fistedge = e;//头插法
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
			p->next = e;//头插法
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
//第一步，创建边节点指针，并且把调用的顶点设置为1，表示遍历过，然后进行操作
//第二步，把p指针给赋值为当前节点对应的第一个边节点
//第三部，边节点看是否遍历过，没有的话就向后；
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
//第一步，初始化visited[i]数组，全部设置为0
//第二部，从第一个开始，遍历visited数组
//第三步若没有遇到过，就调深度优先算法


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