#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> 
#include <time.h>
#include"Node.h"
int Node::GetElem(Node* l, int i, int* e)//找到第i个元素的值是多少，并返回到e里面；
{
	int j; Node* p;//j用来计数,p是指针，指向下一个链表；
	p = l->next; j = 1;
	while (p && j < i)//当j=i是，就找到了；
	{
		p = p->next;//p每次都指向下一个结点地址
		j++;
	}//进行循环，目的是找到元素i;
	if (!p || j > i)
		return 0;
	*e = p->date;
	return 1;
}
int Node::ListInsert(Node** L, int i, int e)
//Node**是二级指针，是该链表的头指针
//指向第一个节点的指针或者头结点的指针
//i是想要插入的位置，e是想要插入的数据
{
	int j;//j是计数器
	Node* p;//p的作用是指向下一个结点
	p = *L; j = 1;//p从头指针的解引用开始，在这里是第一个元素的指针；
	while (p && j < 1)
	{
		p = p->next;
		j++;
	}//循环
	if (!p || j > 1)
	{
		return 0;
	}
	Node* s = (Node*)malloc(sizeof(Node));//创建一个结点。动态的内存分配
	s->date = e;//把该节点的内存分配给
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