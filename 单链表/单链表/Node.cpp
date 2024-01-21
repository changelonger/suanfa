#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> 
#include <time.h>
#include"Node.h"
int Node::GetElem(Node* l, int i, int* e)//�ҵ���i��Ԫ�ص�ֵ�Ƕ��٣������ص�e���棻
{
	int j; Node* p;//j��������,p��ָ�룬ָ����һ������
	p = l->next; j = 1;
	while (p && j < i)//��j=i�ǣ����ҵ��ˣ�
	{
		p = p->next;//pÿ�ζ�ָ����һ������ַ
		j++;
	}//����ѭ����Ŀ�����ҵ�Ԫ��i;
	if (!p || j > i)
		return 0;
	*e = p->date;
	return 1;
}
int Node::ListInsert(Node** L, int i, int e)
//Node**�Ƕ���ָ�룬�Ǹ������ͷָ��
//ָ���һ���ڵ��ָ�����ͷ����ָ��
//i����Ҫ�����λ�ã�e����Ҫ���������
{
	int j;//j�Ǽ�����
	Node* p;//p��������ָ����һ�����
	p = *L; j = 1;//p��ͷָ��Ľ����ÿ�ʼ���������ǵ�һ��Ԫ�ص�ָ�룻
	while (p && j < 1)
	{
		p = p->next;
		j++;
	}//ѭ��
	if (!p || j > 1)
	{
		return 0;
	}
	Node* s = (Node*)malloc(sizeof(Node));//����һ����㡣��̬���ڴ����
	s->date = e;//�Ѹýڵ���ڴ�����
	s->next = p->next;
	p->next = s;
	return 1;
}
int Node::ListDelete(Node** l, int i, int* e)
{
	int j;
	Node* p = *l,*q=NULL;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
	{
		return 0;
	}
	p->next =q;
	p = q->next;
	return 1;
}
void Node::CreateList(Node** l, int n)
{
	Node* p, *r;
	int i;
	srand(time(0));
	*l = (Node*)malloc(sizeof(Node));
	r = *l;
	for (int i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->date = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r = NULL;
}
void Node::ClearList(Node** l)
{
	Node* p, *q;
	p = (*l)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*l)->next = NULL;
}
void Node::DisplayList(Node** l, int n)
{
	int i = 0; Node* p = (*l)->next;
	for (i = 1; i <= n; i++)
	{
		printf("%-4d%p\n", (*p).date, p);
		p = p->next;
	}
}