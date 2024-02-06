#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>



typedef char Vertex;
typedef int Edge;
#define MAX 10
#define INFINiTY 65535
struct MGraph
{
	Vertex vexs[MAX];//顶点表
	Edge arc[MAX][MAX];//数组
	int numVertex, numEdge;//图中当顶点数和边数
};

//邻接矩阵
void CreatMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("请输入顶点数和边数：\n");
	scanf("%d%d", &G->numVertex, &G->numEdge);
	for (int i = 0; i < G->numVertex; i++)
	{
		getchar();
		scanf("%c", &G->vexs[i]);
	}
	for (int i = 0; i < G->numVertex; i++)
	{
		for (int j = 0; j < G->numVertex; j++)
		{
			G->arc[i][j] = INFINiTY;//矩阵初始化
		}
	}
	for (k = 0; k < G->numEdge; k++)
	{
		printf("输入边(vi,vj)的上标i,下标j:\n");
		scanf("%d%d", &i, &j);
		G->arc[i][j] = 1;//无向量图，矩阵对称；
		G->arc[j][i] = G->arc[i][j];
	}
	
}
//深度优先遍历，DFS，若为邻接矩阵，代码如下
int visited[MAX];
void DFS(MGraph G, int i)//邻接矩阵的深度优先递归算法
{
	int j;
	visited[i] = 1;//访问过设一
	printf("%c ", G.vexs[i]);//可以改成其他的操作
	for (j = 0; j < G.numVertex; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])//前面代表二者有关系，后面代表这个没有访问过；
			DFS(G, j);//找下一个顶点
	}
}
void DFSTraverse(MGraph G)//邻接矩阵的深度遍历操作
{
	int i;
	for (i = 0; i < G.numVertex; i++)//初始化为0
		visited[i] = 0;
	for (i = 0; i < G.numVertex; i++)
	{
		if (!visited[i])//如果为零
			DFS(G, i);
	}
}
//int main()//用于测试上面的函数
//{
//	////测试数据
//	// 4 5
//	// A B C D
// //    1 0 1
//	// 0 3 1
//	// 2 0 1
//	// 2 1 1
//	// 1 2 1
//	MGraph G;
//	CreatMGraph(&G);
//	DFSTraverse(G);
//	return 0;
//}

#include"Queue.h"
//广度优先遍历,队列知识；
void BFSTraverse(MGraph G)
{
	int i, j;
	sqqueue q;
	for (int i = 0; i < G.numVertex; i++)
		visited[i] = 0;
	initqueue(&q);//初始化辅助用的队列
	for (i = 0; i < G.numVertex; i++)//对每一个顶点进行循环
	{
		if (!visited[i])//没有访问过
		{
			visited[i] = 1;//设置访问过
			printf("%c ", G.vexs[i]);
			enqueue(&q, i);//次顶点入队列
			while (q.front!= q.rear)//队列不为空判断
			{
				dequeue(&q,&i);//队列中元素出队列,并把值赋给i;
				for (j = 0; j < G.numVertex; j++)
				{
					//判断其他顶点是否与当前顶点存在边且没有被访问过
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = 1;//标记访问
						printf("%c ", G.vexs[j]);
						enqueue(&q, j);//此节点入队列
					}
				}

			}
		}
	}
}
int main()
{
	MGraph G;
	CreatMGraph(&G);
	BFSTraverse(G);
	return 0;
}
//9 15
//A B C D E F G H I
//0 1
//0 5
//1 6
//1 8
//1 2
//2 3
//2 8
//3 8
//3 6
//3 7
//3 4
//4 7
//4 5
//5 6
//6 7
//
//





