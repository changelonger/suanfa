#pragma once
//队列满判断：(q->rear + 1) % MAX == q->front
//队列空判断：q->front == q->rear
#include<stdio.h>
#define MAX 10
struct sqqueue
{
	int date[MAX];
	int front;
	int rear;
};
void initqueue(sqqueue* q);
int queuelenth(sqqueue q);
void initqueue(sqqueue* q)
{
	q->front = 0;
	q->rear = 0;
}
int queuelenth(sqqueue q)
{
	return (q.rear - q.front + MAX) % MAX;
}
int enqueue(sqqueue* q, int e)
{
	if ((q->rear + 1) % MAX == q->front)
		return 0;
	q->date[q->rear] = e;
	q->rear = (q->rear + 1) % MAX;
	return 1;
}
int dequeue(sqqueue* q,int *i)
{
	if (q->front == q->rear)
	{
		return 0;
	}
	*i = q->date[q->front];
	q->front = (q->front + 1) % MAX;

	return 1;
}
