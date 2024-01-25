#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX 20
struct sqqueue 
{
	int date[MAX];
	int front;
	int rear;
};
void initqueue(sqqueue* q);
int queuelenth(sqqueue q);

int main()
{
	return 0;
}
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
int dequeue(sqqueue* q)
{
	if (q->front == q->rear)
	{
		return 0;
	}
	q->front = (q->front + 1) % MAX;

	return 1;
}