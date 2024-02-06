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
	Vertex vexs[MAX];//�����
	Edge arc[MAX][MAX];//����
	int numVertex, numEdge;//ͼ�е��������ͱ���
};

//�ڽӾ���
void CreatMGraph(MGraph* G)
{
	int i, j, k, w;
	printf("�����붥�����ͱ�����\n");
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
			G->arc[i][j] = INFINiTY;//�����ʼ��
		}
	}
	for (k = 0; k < G->numEdge; k++)
	{
		printf("�����(vi,vj)���ϱ�i,�±�j:\n");
		scanf("%d%d", &i, &j);
		G->arc[i][j] = 1;//������ͼ������Գƣ�
		G->arc[j][i] = G->arc[i][j];
	}
	
}
//������ȱ�����DFS����Ϊ�ڽӾ��󣬴�������
int visited[MAX];
void DFS(MGraph G, int i)//�ڽӾ����������ȵݹ��㷨
{
	int j;
	visited[i] = 1;//���ʹ���һ
	printf("%c ", G.vexs[i]);//���Ըĳ������Ĳ���
	for (j = 0; j < G.numVertex; j++)
	{
		if (G.arc[i][j] == 1 && !visited[j])//ǰ���������й�ϵ������������û�з��ʹ���
			DFS(G, j);//����һ������
	}
}
void DFSTraverse(MGraph G)//�ڽӾ������ȱ�������
{
	int i;
	for (i = 0; i < G.numVertex; i++)//��ʼ��Ϊ0
		visited[i] = 0;
	for (i = 0; i < G.numVertex; i++)
	{
		if (!visited[i])//���Ϊ��
			DFS(G, i);
	}
}
//int main()//���ڲ�������ĺ���
//{
//	////��������
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
//������ȱ���,����֪ʶ��
void BFSTraverse(MGraph G)
{
	int i, j;
	sqqueue q;
	for (int i = 0; i < G.numVertex; i++)
		visited[i] = 0;
	initqueue(&q);//��ʼ�������õĶ���
	for (i = 0; i < G.numVertex; i++)//��ÿһ���������ѭ��
	{
		if (!visited[i])//û�з��ʹ�
		{
			visited[i] = 1;//���÷��ʹ�
			printf("%c ", G.vexs[i]);
			enqueue(&q, i);//�ζ��������
			while (q.front!= q.rear)//���в�Ϊ���ж�
			{
				dequeue(&q,&i);//������Ԫ�س�����,����ֵ����i;
				for (j = 0; j < G.numVertex; j++)
				{
					//�ж����������Ƿ��뵱ǰ������ڱ���û�б����ʹ�
					if (G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = 1;//��Ƿ���
						printf("%c ", G.vexs[j]);
						enqueue(&q, j);//�˽ڵ������
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





