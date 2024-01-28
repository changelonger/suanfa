#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> 
#include <time.h>
#include"Node.h"
void Node::CreateList(Node** l, int n)
{
	Node* p, * r;
	int i;
	srand(time(0));

	/**l = (Node*)malloc(sizeof(Node));*/
	(*l)->date = n;
	r = *l;
	for (int i = 0; i < (*l)->date; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->date = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r = NULL;
}
int Node::ListLenth(Node*p0)
{
	return p0->date;
}

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
void Node::ListInsert(Node** L, int i, int e)
//Node**�Ƕ���ָ�룬�Ǹ������ͷָ��
//ָ���һ���ڵ��ָ�����ͷ����ָ��
//i����Ҫ�����λ�ã�e����Ҫ���������
{
	int j;//j�Ǽ�����
	Node* p;//p��������ָ����һ�����
	p = *L; j = 1;//p��ͷָ��Ľ����ÿ�ʼ���������ǵ�һ��Ԫ�ص�ָ�룻
	while (j < i)
	{
		p = p->next;
		j++;
	}//ѭ��
	Node* s = (Node*)malloc(sizeof(Node));//����һ����㡣��̬���ڴ����
	s->date = e;//�Ѹýڵ�����������ݸ�ֵΪe
	s->next = p->next;//sָ����ָ��p����һ��Ԫ��
	p->next = s;
	(*L)->date++;
}
void Node::ListDelete(Node** l, int i)
{
	int j;
	Node* p = *l,*q;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		j++;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	(*l)->date--;
	
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